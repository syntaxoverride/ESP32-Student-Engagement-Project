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

def update_platformio_ini(station_num, platformio_path):
    """Temporarily update platformio.ini with station number."""
    # Convert Path to string for file operations
    platformio_str = str(platformio_path)
    
    # Read the file
    with open(platformio_str, 'r') as f:
        content = f.read()
    
    # Backup original
    backup_path = platformio_str + '.backup'
    shutil.copy2(platformio_str, backup_path)
    
    # Replace STATION_NUMBER line
    pattern = r'-DSTATION_NUMBER=\d+'
    replacement = f'-DSTATION_NUMBER={station_num}'
    new_content = re.sub(pattern, replacement, content)
    
    # Write updated content
    with open(platformio_str, 'w') as f:
        f.write(new_content)
    
    return backup_path

def restore_platformio_ini(platformio_path, backup_path):
    """Restore original platformio.ini from backup."""
    platformio_str = str(platformio_path)
    if os.path.exists(backup_path):
        shutil.copy2(backup_path, platformio_str)
        os.remove(backup_path)

def main():
    # Find PlatformIO command
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
    
    # Get station number from command line or prompt
    if len(sys.argv) > 1:
        try:
            station_num = int(sys.argv[1])
        except ValueError:
            print("Error: Station number must be an integer")
            sys.exit(1)
    else:
        # Prompt for station number
        try:
            station_num = int(input("Enter station number (1, 2, 3, etc.): "))
        except ValueError:
            print("Error: Station number must be an integer")
            sys.exit(1)
        except KeyboardInterrupt:
            print("\nCancelled")
            sys.exit(0)
    
    if station_num < 1:
        print("Error: Station number must be 1 or greater")
        sys.exit(1)
    
    # Determine action (build, upload, or both)
    action = "upload"  # Default to upload
    if len(sys.argv) > 2:
        action = sys.argv[2].lower()
    
    # Get platformio.ini path
    script_dir = Path(__file__).parent
    platformio_path = script_dir / "platformio.ini"
    
    if not platformio_path.exists():
        print(f"Error: platformio.ini not found at {platformio_path}")
        sys.exit(1)
    
    # Update platformio.ini with station number
    backup_path = update_platformio_ini(station_num, platformio_path)
    
    print(f"\n{'='*60}")
    print(f"Building for Station #{station_num}")
    print(f"Wi-Fi SSID will be: CyberLab-ESP32 {station_num}")
    print(f"Portal Title will be: ESP32 Lab Portal #{station_num}")
    print(f"{'='*60}\n")
    
    # Build PlatformIO command
    if action == "build":
        cmd = pio_cmd + ["run", "-e", "esp32dev"]
    elif action == "upload":
        # Upload and then start monitor automatically
        cmd = pio_cmd + ["run", "--target", "upload", "--target", "monitor", "-e", "esp32dev"]
    elif action == "monitor":
        cmd = pio_cmd + ["device", "monitor"]
    else:
        # Restore before exiting
        restore_platformio_ini(platformio_path, backup_path)
        print(f"Unknown action: {action}")
        print("Usage: python build_station.py [station_number] [build|upload|monitor]")
        sys.exit(1)
    
    # Run the command
    exit_code = 0
    try:
        result = subprocess.run(cmd, check=False)
        exit_code = result.returncode
    except KeyboardInterrupt:
        print("\n\nBuild cancelled by user")
        exit_code = 1
    except Exception as e:
        print(f"Error running PlatformIO: {e}")
        exit_code = 1
    finally:
        # Always restore platformio.ini
        restore_platformio_ini(platformio_path, backup_path)
    
    sys.exit(exit_code)

if __name__ == "__main__":
    main()
