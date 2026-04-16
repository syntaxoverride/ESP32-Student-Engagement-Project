# VaultGuard AI

Welcome to VaultGuard AI! Get ready to build your own intelligent security system from the ground up. In this hands-on lab, you'll work with ESP32 microcontrollers to create two powerful security tools: a smart phishing email detector and a real-time bank vault monitoring system.

You'll start by building a web-based phishing detector that you can customize with your own rules and keywords. Then, you'll set up sensors to monitor a bank vault, tracking door access and detecting any suspicious vibrations. Along the way, you'll dive into engineering principles, computer science concepts, cybersecurity fundamentals, and even some AI-driven decision-making.

Whether you're a beginner or have some experience, this lab is designed to be approachable and fun. You'll leave with a working security system, new skills, and a better understanding of how technology can help keep things safe. Let's build something awesome together!

---

## VaultGuard AI Portal

An outreach-friendly, hands-on project for grades 7–12 that combines computer science, cybersecurity, and AI concepts using an ESP32-WROOM. The device hosts a local Wi-Fi access point with two interactive labs:

1. **VaultGuard AI**: AI Phishing Detector - Analyze messages for phishing threats
2. **Security Center**: Bank Vault Security System - Access control and intrusion detection

## Features

- **Plug-and-Play**: Pre-flashed firmware; students only connect to Wi-Fi and open a webpage
- **Offline Operation**: Works completely offline with no internet or cloud dependencies
- **Explainable AI**: Provides risk scores with detailed reasons (urgency language, credential requests, etc.)
- **Adjustable Strictness**: Three levels (Strict, Normal, Lenient) to demonstrate tradeoffs
- **Mobile-First UI**: Optimized for phones and tablets with large tap targets
- **Web-Based Builder**: Students customize the system through a visual interface - no coding required!
- **Runtime Configuration**: Modify keywords, scoring, samples, themes, and quiz questions in real-time
- **Facilitator Reset**: Password-protected reset for quick cleanup between groups

## Quick Start

1. **Flash the firmware** to your ESP32-WROOM (see Setup Instructions below)
2. **Connect sensors** (optional - see Security Center Pinout below):
   - Touch sensor: GPIO 14 (digital touch switch module)
   - Vibration sensor: GPIO 27 (SW-420 module)
3. **Power on** the ESP32 (USB cable or power adapter)
4. **Connect** to Wi-Fi network: `VaultGuard-AI` (or `VaultGuard-AI 1`, `VaultGuard-AI 2`, etc. if customized)
5. **Open browser** to `http://vaultguard.local` or `http://192.168.4.1`
6. **Choose a lab**:
   - **VaultGuard AI**: Analyze messages for phishing threats
   - **Security Center**: Monitor bank vault security system

## Requirements

- ESP32-WROOM development board (or compatible ESP32)
- USB cable (data-capable)
- Computer for initial flashing
- PlatformIO (VS Code extension or CLI)

### Optional (for Security Center):
- SW-420 vibration sensor module (for intrusion detection)
- Digital touch switch (for door sensor on GPIO 14)

## Setup Instructions

### Part 1: Installing PlatformIO

#### Option A: Using VS Code with PlatformIO Extension (Recommended)

1. **Install VS Code**: Download from https://code.visualstudio.com/
2. **Install PlatformIO Extension**:
   - Open VS Code
   - Click Extensions icon (or `Ctrl+Shift+X` / `Cmd+Shift+X`)
   - Search for `PlatformIO IDE`
   - Click Install
   - Wait for installation (2-5 minutes)
   - Reload VS Code if prompted
3. **Verify Installation**: Look for PlatformIO icon (alien head) in bottom status bar

#### Option B: Using PlatformIO Core (Command Line)

**macOS/Linux:**
```bash
python3 -m pip install --user platformio
pio --version  # Verify installation
```

**Windows:**
```bash
python -m pip install --user platformio
pio --version  # Verify installation
```

### Part 2: Opening the Project

1. Open VS Code
2. Click **File** → **Open Folder**
3. Navigate to the `ESP-32` project folder
4. VS Code will detect the PlatformIO project automatically

### Part 3: Connecting the ESP32

1. Connect ESP32 to computer via USB cable (must be data-capable, not charge-only)
2. **Verify Connection**:
   - **Windows**: Device Manager → Ports (COM & LPT) → Note COM port number
   - **macOS**: Terminal → `ls /dev/cu.*` → Note device name
   - **Linux**: Terminal → `ls /dev/ttyUSB*` or `ls /dev/ttyACM*` → Note device name

3. **Install USB Drivers** (if device not detected):
   - **CH340**: http://www.wch.cn/downloads/CH341SER_EXE.html
   - **CP210x**: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers

### Part 4: Building and Uploading

#### Using VS Code (Recommended):

1. Click **PlatformIO icon** in left sidebar
2. Under **PROJECT TASKS** → **esp32dev**:
   - Click **Build** (or `Ctrl+Alt+B` / `Cmd+Option+B`)
   - Wait for build to complete
   - Click **Upload** (or `Ctrl+Alt+U` / `Cmd+Option+U`)
   - **Note**: If upload fails, put ESP32 in bootloader mode:
     - Hold BOOT button
     - Press and release RESET
     - Release BOOT
     - Try upload again

#### Using Command Line:

```bash
pio run                    # Build
pio run --target upload    # Upload
pio device monitor         # View serial output
```

### Part 5: Verifying Upload

1. Open Serial Monitor (115200 baud):
   - VS Code: Click **Monitor** under PROJECT TASKS
   - Or: `pio device monitor`
2. You should see:
   ```
   === VaultGuard AI ===
   Station Number: 1
   AP SSID: VaultGuard-AI 1
   AP IP: 192.168.4.1
   HTTP server started
   Ready for connections!
   ```

### Part 6: Testing the Device

1. **Connect to Wi-Fi**: Look for network `VaultGuard-AI` (or `VaultGuard-AI 1`, etc.)
2. **Access Portal**: Navigate to `http://vaultguard.local` or `http://192.168.4.1`
3. **Test Interface**: Try analyzing sample messages

## Security Center Pinout Guide

### Pin Assignments

| Sensor | Wire | ESP32 Pin | Side of Board | Label to Look For |
|--------|------|-----------|---------------|-------------------|
| **Door (Touch)** | VCC | 3.3V | Either side | "3V3" or "3.3V" |
| **Door (Touch)** | GND | GND | Either side | "GND" |
| **Door (Touch)** | SIG | **GPIO 14** | **LEFT** | "D14" or "14" |
| **Vibration** | VCC | 3.3V | Either side | "3V3" or "3.3V" |
| **Vibration** | GND | GND | Either side | "GND" |
| **Vibration** | SIG | **GPIO 27** | **LEFT** | "D27" or "27" |

### Why These Pins?

- **GPIO 14** (Left side) - Safe pin for digital input
- **GPIO 27** (Left side) - Safe pin, NOT a boot pin
- **GPIO 15 was avoided** - It's a strapping/boot pin that can cause issues!

### Wiring Diagram

```
                    ESP32 BOARD
                   (USB at bottom)
                   
    LEFT SIDE                      RIGHT SIDE
    ─────────                      ──────────
    
    EN (top)                       3.3V ←─┬── Touch VCC
    GPIO36                               └── Vibration VCC
    GPIO39                         
    GPIO34                         GND  ←─┬── Touch GND
    GPIO35                               └── Vibration GND
    GPIO32                         
    GPIO33                         GPIO15
    GPIO25                         GPIO2
    GPIO26                         GPIO4
 →  GPIO27 ←── Vibration SIG       ...
 →  GPIO14 ←── Touch SIG (DOOR)    
    GPIO12                         
    ...                            ...
```

### Step-by-Step Wiring

#### Door Sensor (Touch Switch) - LEFT SIDE

1. Find **GPIO 14** on the LEFT side of your ESP32 (look for "D14" label)
2. Connect:
   - Touch Switch **VCC** → ESP32 **3.3V**
   - Touch Switch **GND** → ESP32 **GND**
   - Touch Switch **SIG/DO** → ESP32 **GPIO 14**

#### Vibration Sensor - LEFT SIDE

1. Find **GPIO 27** on the LEFT side of your ESP32 (look for "D27" label)
2. Connect:
   - Vibration Switch **VCC** → ESP32 **3.3V**
   - Vibration Switch **GND** → ESP32 **GND**
   - Vibration Switch **SIG** → ESP32 **GPIO 27**

### Verification

After uploading firmware, open Serial Monitor (115200 baud). You should see:

```
Door sensor (digital touch switch) initialized on GPIO 14
Vibration sensor initialized on GPIO 27 with INTERRUPT
Using hardware interrupt to catch brief pulses!
Initial pin state: HIGH
Security Center sensors ready!
```

**If vibration never triggers** — use the module’s **DO/D0** output (not **AO**), confirm **SIG → GPIO 27**, and adjust the **sensitivity potentiometer** on the SW-420 until you see `*** VIBRATION DETECTED via interrupt!` in the Serial Monitor when you tap the sensor.

### Security Scenarios

| Scenario | Door Sensor | Vibration Sensor | Vault Status |
|----------|-------------|------------------|--------------|
| Normal | CLOSED | SECURE | SECURE |
| Authorized Access | OPEN | SECURE | DOOR OPEN |
| Break-in Attempt | CLOSED | DETECTED | ALERT |
| Full Breach | OPEN | DETECTED | BREACH |

## Customizing Station Numbers

When deploying multiple ESP32 units, customize each station's Wi-Fi name and portal title:

**Method 1: Manual Edit (Simplest - Recommended)**

1. Open `platformio.ini`
2. Find the line: `-DSTATION_NUMBER=1`
3. Change the number to your station (e.g., `-DSTATION_NUMBER=2`, `-DSTATION_NUMBER=15`)
4. Build and upload normally using VS Code's PlatformIO extension

**Method 2: Python Script (Command Line)**

```bash
# Interactive prompt
python3 build_station.py

# Or specify station number directly
python3 build_station.py 5        # Build and upload Station #5
python3 build_station.py 12 build # Just build Station #12
python3 build_station.py 8 upload # Just upload Station #8
```

**Method 3: Direct PlatformIO Command**

```bash
pio run --target upload -e esp32dev --build-flags="-DSTATION_NUMBER=15"
```

**Result:**
- **Wi-Fi SSID**: `VaultGuard-AI 1`, `VaultGuard-AI 15`, etc.
- **Portal Title**: `VaultGuard AI Portal #1`, `VaultGuard AI Portal #15`, etc.

## Project Structure

```
ESP-32/
├── README.md              # This file (complete documentation)
├── FACILITATOR_GUIDE.md   # 2-hour session guide
├── STUDENT_HANDOUT.md     # Student instructions
├── platformio.ini         # PlatformIO configuration
├── build_station.py       # Dynamic station numbering script
└── src/
    ├── main.cpp           # Main application code
    ├── classifier/
    │   ├── classifier.h   # Classifier interface
    │   └── classifier.cpp # Scoring and analysis logic
    ├── config/
    │   ├── config.h       # Configuration management
    │   └── config.cpp
    ├── sensors/
    │   ├── sensors.h      # Security Center sensors
    │   └── sensors.cpp     # Touch & vibration sensor logic
    ├── stats/
    │   ├── stats.h        # Statistics tracking
    │   └── stats.cpp
    └── web/
        ├── index_html.h           # VaultGuard AI UI
        ├── splash_html.h          # Main menu
        ├── security_html.h        # Security Center menu
        └── security_dashboard_html.h  # Security dashboards
```

## How It Works

### VaultGuard AI (AI Phishing Detector)

1. **Wi-Fi Access Point**: ESP32 creates an open Wi-Fi network named `VaultGuard-AI`
2. **DNS Redirect**: DNS server directs all requests to the ESP32's web server
3. **Web Interface**: Students access a mobile-friendly webpage to analyze messages
4. **Classifier Engine**: Rule-based scoring system analyzes messages for phishing indicators:
   - Urgency language
   - Credential requests
   - Reward bait
   - Impersonation cues
   - Financial pressure
   - Suspicious links
5. **Results Display**: Shows verdict (Safe/Suspicious), risk score (0-100%), and detected signals

### Security Center (Bank Vault Security System)

1. **Touch Sensor**: Digital touch switch on GPIO 14 detects authorized access
2. **Vibration Sensor**: SW-420 module on GPIO 27 detects break-in attempts
3. **Real-time Monitoring**: Live dashboards show access control and intrusion detection
4. **Vault Status**: Dynamic status indicator shows SECURE, ACCESS GRANTED, or BREACH DETECTED
5. **Security Scenarios**: Students learn about access control and intrusion detection systems

## Strictness Levels

- **Strict** (threshold: 45): More sensitive, flags more messages as suspicious
- **Normal** (threshold: 60): Balanced detection (default)
- **Lenient** (threshold: 75): Less sensitive, fewer false positives

## Sample Messages

The interface includes 6 pre-loaded sample messages:
1. Normal Message (benign)
2. Urgent Account (suspicious)
3. Prize Scam (suspicious)
4. IT Impersonation (suspicious)
5. Payment Pressure (suspicious)
6. Suspicious Link (suspicious)

## Technical Details

- **Framework**: Arduino (via PlatformIO)
- **Libraries**: WiFi, WebServer, DNSServer (built-in ESP32)
- **Network**: 192.168.4.1/24
- **Port**: 80 (HTTP)
- **DNS Port**: 53
- **Serial Monitor**: 115200 baud

## Classroom Use

### 2-Hour Build Experience

This project is designed for a **2-hour hands-on session** where students customize the phishing detector through a web-based Builder interface. See [FACILITATOR_GUIDE.md](FACILITATOR_GUIDE.md) for complete session plans.

**Key Activities**:
- **VaultGuard AI**: Students modify keywords, scoring weights, and sample messages
- **VaultGuard AI**: Create custom themes and quiz questions
- **Security Center**: Monitor access control and intrusion detection
- **Security Center**: Learn about physical security systems and sensors
- **Both Labs**: Understand CS concepts: pattern recognition, algorithm tuning, rule-based systems, sensor integration
- **Both Labs**: Learn cybersecurity: phishing detection, threat signals, access control, physical security

### For Facilitators

1. Power on ESP32
2. Wait 30 seconds for startup
3. Tell students: "Connect to Wi-Fi: VaultGuard-AI"
4. Tell students: "Open your browser and go to vaultguard.local or 192.168.4.1"
5. Students choose a lab:
   - **VaultGuard AI**: Phishing detection and analysis
   - **Security Center**: Bank vault security monitoring
6. Guide students through activities in their chosen lab
7. Use facilitator reset between groups: `http://vaultguard.local/reset` (password: `RESET2025`)

### Builder Tab Features

Students can customize:
- **Keywords**: Add/remove phishing detection keywords by category
- **Sample Messages**: Create custom test messages
- **Scoring Weights**: Adjust point values for each signal type
- **Theme**: Customize colors and visual style
- **Quiz**: Add custom cybersecurity questions

All changes are in-memory and reset on reboot. Students can experiment freely!

### Reset Procedures

**Student Reset**:
- Use "Reset to Defaults" button in Builder tab
- Resets only student customizations

**Facilitator Reset** (between groups):
1. Navigate to: `http://vaultguard.local/reset`
2. Enter password: `RESET2025`
3. Click "RESET SYSTEM"
4. Resets everything: configs, statistics, all customizations

**Hard Reset** (if system fails):
1. Unplug USB/power
2. Wait 10 seconds
3. Plug back in
4. Device resets automatically

## Troubleshooting

### Can't see "VaultGuard-AI" Wi-Fi network

**Solutions:**
1. Check Serial Monitor - does it show "AP SSID: VaultGuard-AI"?
2. If not, the firmware may not have uploaded correctly - try uploading again
3. Move closer to the ESP32 (range is limited, ~30-50 feet)
4. Restart the ESP32 (unplug and replug USB, or press RESET button)

### Page won't load

**Solutions:**
1. Navigate to: `http://vaultguard.local` or `http://192.168.4.1`
2. If `vaultguard.local` doesn't work, use the IP address `192.168.4.1` instead
3. Clear browser cache and try again
4. Try a different browser

### "Unable to connect" or page won't load

**Solutions:**
1. Verify you're connected to "VaultGuard-AI" Wi-Fi
2. Check Serial Monitor for errors
3. Try restarting the ESP32
4. Make sure no firewall is blocking local network access

### Analyze button does nothing

**Solutions:**
1. Check browser console for errors (F12 → Console tab)
2. Make sure you entered a message
3. Try a sample message chip first
4. Check Serial Monitor for server errors

### Upload fails with "Timed out waiting for packet header"

**Solutions:**
1. Put ESP32 in bootloader mode manually:
   - Hold BOOT button
   - Press and release RESET
   - Release BOOT
   - Try upload again immediately
2. Try a different USB cable (must be data-capable)
3. Try a different USB port
4. Close other programs that might use the serial port

### "A fatal error occurred: Failed to connect to ESP32"

**Solutions:**
1. Install USB drivers (see Setup Instructions, Part 3)
2. Check Device Manager (Windows) or `ls /dev/cu.*` (macOS) to verify device is detected
3. Try unplugging and replugging the USB cable
4. Restart your computer

### Build fails with memory errors

**Solutions:**
1. The HTML file is large - this is normal
2. If you get "Sketch too big" errors, you may need to:
   - Use a board with more flash memory
   - Or optimize the HTML (remove comments, minify)
3. Check that `board_build.partitions = default.csv` is in platformio.ini

### Security Center sensors not working

**Solutions:**
1. Check Serial Monitor for sensor initialization messages
2. Verify GPIO 14 (touch) and GPIO 27 (vibration) connections (see Security Center Pinout above)
3. **Vibration Sensor**:
   - Check the LED on the module - shake it, LED should light up
   - Verify GPIO 27 is on the LEFT side of the board
   - Check wiring: SIG → GPIO 27, VCC → 3.3V, GND → GND
4. **Door Sensor**:
   - Check Serial Monitor for pin readings
   - Verify GPIO 14 is on the LEFT side of board
   - Activate the touch switch - dashboard should update

## Quick Reference

### Serial Monitor Settings
- **Baud Rate**: 115200
- **Line Ending**: Both NL & CR (or just CR)
- **Auto-scroll**: Enabled

### Default Network Settings
- **SSID**: VaultGuard-AI (or VaultGuard-AI 1, 2, etc. if customized)
- **IP Address**: 192.168.4.1
- **Password**: None (open network)

### Key URLs
- **Portal**: http://vaultguard.local (or http://192.168.4.1)
- **Facilitator Reset**: http://vaultguard.local/reset (password: `RESET2025`)
- **Note**: Some devices may not support `.local` domains - use IP address as fallback

### Reset Procedure
1. Unplug USB cable
2. Wait 2 seconds
3. Plug USB cable back in
4. Device will boot and be ready in ~10-30 seconds

## Safety & Privacy

- **No data collection**: Messages are analyzed in real-time, not stored
- **Offline operation**: No internet required, no external services
- **Educational focus**: Teaches defensive thinking, not exploitation
- **Age-appropriate**: Content designed for grades 7-12

## License

This project is designed for educational outreach use.

## Support

For technical questions about the ESP32 or PlatformIO, consult:
- [ESP32 Arduino Core Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [PlatformIO Documentation](https://docs.platformio.org/)

---

**Note**: The ESP32 creates its own Wi-Fi network. Devices connected to it will not have internet access. This is normal and expected behavior.
