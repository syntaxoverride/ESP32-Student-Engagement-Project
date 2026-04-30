#!/usr/bin/env python3
"""
Dynamic build script for ESP32 stations.
Prompts for station number and builds/uploads with that number.
Temporarily modifies platformio.ini, then restores it.
"""
import sys
import subprocess
import os
import re
import shutil
from pathlib import Path

def find_pio_command():
    """Try multiple methods to find PlatformIO command."""
    # Method 1: Try 'pio' directly (if in PATH)
    try:
        result = subprocess.run(["pio", "--version"], 
                               capture_output=True, 
                               timeout=2)
        if result.returncode == 0:
            return ["pio"]
    except (FileNotFoundError, subprocess.TimeoutExpired):
        pass
    
    # Method 2: Try 'python3 -m platformio'
    try:
        result = subprocess.run(["python3", "-m", "platformio", "--version"], 
                               capture_output=True, 
                               timeout=2)
        if result.returncode == 0:
            return ["python3", "-m", "platformio"]
    except (FileNotFoundError, subprocess.TimeoutExpired):
        pass
    
    # Method 3: Try PlatformIO Core location (VS Code extension)
    home = Path.home()
    pio_paths = [
        home / ".platformio" / "penv" / "bin" / "pio",
        home / ".platformio" / "penv" / "Scripts" / "pio.exe",  # Windows
    ]
    
    for pio_path in pio_paths:
        if pio_path.exists():
            return [str(pio_path)]
    
    # Method 4: Try common installation paths
    common_paths = [
        "/usr/local/bin/pio",
        "/opt/homebrew/bin/pio",
    ]
    
    for path in common_paths:
        if os.path.exists(path):
            return [path]
    
    return None

def settings_for_station(station_num):
    """Per-station build settings. Add new flags here as the project grows."""
    # Stagger across the three non-overlapping 2.4GHz channels so adjacent
    # stations (WS1 next to WS2) never collide on the same channel.
    channels = [1, 6, 11]
    return {
        "STATION_NUMBER": station_num,
        "WIFI_CHANNEL": channels[(station_num - 1) % len(channels)],
    }

def update_platformio_ini(station_num, platformio_path):
    """Temporarily update platformio.ini with per-station build flags."""
    platformio_str = str(platformio_path)

    with open(platformio_str, 'r') as f:
        content = f.read()

    backup_path = platformio_str + '.backup'
    shutil.copy2(platformio_str, backup_path)

    new_content = content
    for flag, value in settings_for_station(station_num).items():
        pattern = rf'-D{flag}=\d+'
        replacement = f'-D{flag}={value}'
        new_content = re.sub(pattern, replacement, new_content)

    with open(platformio_str, 'w') as f:
        f.write(new_content)

    return backup_path

def restore_platformio_ini(platformio_path, backup_path):
    """Restore original platformio.ini from backup."""
    platformio_str = str(platformio_path)
    if os.path.exists(backup_path):
        shutil.copy2(backup_path, platformio_str)
        os.remove(backup_path)

def print_banner():
    print(f"\n{'='*60}")
    print("  VaultGuard AI  -  ESP32 Station Builder")
    print(f"{'='*60}")
    print("  [1-99]  Flash a station number")
    print("  [m]     Open serial monitor")
    print("  [q]     Quit")
    print(f"{'='*60}")


def prompt_station():
    """Prompt for station number. Returns (station_num, action) or None to quit."""
    choice = input("\nEnter station number (or m/q): ").strip().lower()

    if choice == 'q':
        return None
    if choice == 'm':
        return (0, "monitor")

    try:
        station_num = int(choice)
    except ValueError:
        print("Error: Enter a number, 'm', or 'q'")
        return prompt_station()

    if station_num < 1:
        print("Error: Station number must be 1 or greater")
        return prompt_station()

    return (station_num, "upload")


def run_once(pio_cmd, station_num, action, platformio_path):
    """Run a single build/upload/monitor cycle. Returns the exit code."""
    backup_path = None

    if action != "monitor":
        backup_path = update_platformio_ini(station_num, platformio_path)
        settings = settings_for_station(station_num)
        print(f"\n{'='*60}")
        print(f"Building for Station #{station_num}")
        print(f"Wi-Fi SSID will be: VaultGuard-AI {station_num}")
        print(f"Wi-Fi Channel:     {settings['WIFI_CHANNEL']}")
        print(f"Portal Title will be: VaultGuard AI Portal #{station_num}")
        print(f"{'='*60}\n")

    if action == "build":
        cmd = pio_cmd + ["run", "-e", "esp32dev"]
    elif action == "upload":
        cmd = pio_cmd + ["run", "--target", "upload", "-e", "esp32dev"]
    elif action == "monitor":
        cmd = pio_cmd + ["device", "monitor"]
    else:
        if backup_path:
            restore_platformio_ini(platformio_path, backup_path)
        print(f"Unknown action: {action}")
        return 1

    exit_code = 0
    try:
        result = subprocess.run(cmd, check=False)
        exit_code = result.returncode
    except KeyboardInterrupt:
        print("\n\nCancelled by user")
        exit_code = 1
    except Exception as e:
        print(f"Error running PlatformIO: {e}")
        exit_code = 1
    finally:
        if backup_path:
            restore_platformio_ini(platformio_path, backup_path)

    return exit_code


def main():
    pio_cmd = find_pio_command()
    if not pio_cmd:
        print("Error: PlatformIO not found!")
        print("\nTried to find PlatformIO using:")
        print("  - 'pio' command in PATH")
        print("  - 'python3 -m platformio'")
        print("  - PlatformIO Core installation (~/.platformio/penv/bin/pio)")
        print("\nPlease install PlatformIO:")
        print("  - VS Code: Install 'PlatformIO IDE' extension")
        print("  - CLI: pip install platformio")
        print("  - Or: python3 -m pip install platformio")
        sys.exit(1)

    script_dir = Path(__file__).parent
    platformio_path = script_dir / "platformio.ini"

    if not platformio_path.exists():
        print(f"Error: platformio.ini not found at {platformio_path}")
        sys.exit(1)

    # If command-line args are provided, run once and exit (non-interactive)
    if len(sys.argv) > 1:
        try:
            station_num = int(sys.argv[1])
        except ValueError:
            print("Error: Station number must be an integer")
            sys.exit(1)
        if station_num < 1:
            print("Error: Station number must be 1 or greater")
            sys.exit(1)
        action = sys.argv[2].lower() if len(sys.argv) > 2 else "upload"
        sys.exit(run_once(pio_cmd, station_num, action, platformio_path))

    # Interactive loop
    try:
        while True:
            print_banner()
            selection = prompt_station()

            if selection is None:
                print("\nGoodbye!")
                break

            station_num, action = selection
            exit_code = run_once(pio_cmd, station_num, action, platformio_path)

            if exit_code == 0:
                print(f"\n✓ Done successfully!")
            else:
                print(f"\n✗ Finished with errors (exit code {exit_code})")

            input("\nPress Enter to return to menu...")

    except KeyboardInterrupt:
        print("\n\nGoodbye!")
        sys.exit(0)

if __name__ == "__main__":
    main()
