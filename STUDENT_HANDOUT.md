# Student Guide: VaultGuard AI

## Welcome!

Today you'll explore two security systems: an AI phishing detector and a bank vault monitoring system! You'll learn about cybersecurity, computer science, and how sensors work in physical security.

**Everything is web-based** - no coding required! Just use your phone, tablet, or laptop.

---

## Getting Started

### Step 1: Assemble Your Breadboard

**Important**: Always unplug the ESP32 before connecting or disconnecting wires!

Your facilitator will guide you through assembling the breadboard. Here's what you'll be building:

**What You Need**:
- ESP32-WROOM board
- Breadboard
- 6 jumper wires
- Door sensor (touch switch)
- Vibration sensor (SW-420)
- USB cable

**Quick Assembly Guide**:

**Note**: The ESP32 is already placed on the breadboard. You'll connect the sensors to it.

1. **Connect Door Sensor**
   - VCC (red) → ESP32 3.3V
   - GND (black) → ESP32 GND
   - SIG (yellow/white) → ESP32 GPIO 14 (LEFT side - look for "D14")

3. **Connect Vibration Sensor**
   - VCC (red) → ESP32 3.3V (can share with door sensor)
   - GND (black) → ESP32 GND (can share with door sensor)
   - SIG (yellow/white) → ESP32 GPIO 27 (LEFT side - look for "D27")

4. **Double-Check Connections**
   - Door sensor SIG → GPIO 14 (LEFT)
   - Vibration sensor SIG → GPIO 27 (LEFT)
   - Both sensors have power (VCC → 3.3V, GND → GND)
   - No wires are touching each other

5. **Power On**
   - Connect USB cable to ESP32
   - Connect other end to power (USB adapter or laptop)
   - Watch for LED to light up
   - Wait 30 seconds for startup

**Troubleshooting**:
- **LED doesn't light**: Check USB connection, try different cable/port
- **ESP32 gets hot**: Unplug immediately! Check for short circuits
- **Sensors don't work**: Verify all wires are connected correctly
- **Can't find pins**: Ask your facilitator for help identifying GPIO 14 and GPIO 27

---

### Step 2: Connect to Wi-Fi

Follow these steps to get connected:

1. Open Wi-Fi settings on your device
2. Connect to: **VaultGuard-AI** (or **VaultGuard-AI 1**, **VaultGuard-AI 2**, etc. if your facilitator tells you a specific number)
3. Open a web browser
4. Go to: **vaultguard.local** (or **192.168.4.1** if vaultguard.local doesn't work)

### Step 2: Choose Your Lab

Once connected, you'll see a splash page with two options:

**Option A: VaultGuard AI (AI Phishing Detector)**
- **Analyzer**: Test messages to see if they're suspicious
- **Statistics**: See patterns in detected threats
- **Challenge**: Try to fool the detector!
- **Learn**: Read about phishing techniques
- **Quiz**: Test your cybersecurity knowledge
- **Builder**: Customize the system (this is where the fun begins!)

**Option B: Security Center (Bank Vault Monitoring)**
- **Door Sensor Dashboard**: Monitor vault door access in real-time
- **Vibration Sensor Dashboard**: Detect and track intrusion attempts
- **Live Status**: See security alerts and activity counts

---

## Progressive Challenges

Work through these challenges at your own pace. Each builds on the last!

### Challenge 1: Add Keywords (10 minutes)

**Goal**: Add new words that the detector should look for

**Steps**:
1. Go to **Builder** tab
2. Find **Keywords Manager** section
3. Select a category (try "Urgency Language")
4. Type a new keyword (like "emergency" or "critical")
5. Click **Add**
6. Click **Save Keywords**
7. Go to **Analyzer** tab and test a message with your keyword!

**Try This**: Add keywords to different categories and see how it changes detection.

---

### Challenge 2: Create Sample Messages (10 minutes)

**Goal**: Create your own test messages

**Steps**:
1. Go to **Builder** tab → **Sample Messages**
2. Type a message in the text box
   - Try creating one "safe" message
   - Try creating one "suspicious" message
3. Click **Add**
4. Click **Save Samples**
5. Go to **Analyzer** tab - your messages should appear as chips!

**Try This**: Create messages that are tricky - maybe they look safe but are actually suspicious.

---

### Challenge 3: Adjust Scoring (15 minutes)

**Goal**: Make the detector more or less sensitive

**Steps**:
1. Go to **Builder** tab → **Scoring Weights**
2. Try increasing all the numbers by 5
3. Click **Save Scoring**
4. Test in **Analyzer** - what changed?
5. Now decrease all numbers by 10
6. Save and test again - what's different?

**Think About**:
- What happens when scores are higher?
- What happens when scores are lower?
- What's the "right" balance?

**Try This**: Find the perfect balance where you catch bad messages but don't flag too many safe ones.

---

### Challenge 4: Add a Quiz Question (15 minutes)

**Goal**: Create educational content

**Steps**:
1. Go to **Builder** tab → **Quiz Builder**
2. Write a question about phishing or cybersecurity
3. Write 4 answer options (A, B, C, D)
4. Select which one is correct
5. Click **Add Question**
6. Click **Save Quiz**
7. Go to **Quiz** tab and find your question!

**Try This**: Create questions about phishing techniques you learned today.

---

### Challenge 5: Complete Customization (20 minutes)

**Goal**: Put it all together!

**Your Mission**: Create your perfect phishing detector configuration

**Include**:
- [ ] Custom keywords in at least 3 categories
- [ ] At least 3 custom sample messages
- [ ] Tuned scoring weights
- [ ] At least 2 custom quiz questions

**Test Everything**:
- Try your samples in Analyzer
- Check Statistics to see patterns
- Try Challenge mode with your settings
- Take your own quiz!

**Share**: Show your configuration to a neighbor. What did you do differently?

---

## Security Center Activities

If you chose the Security Center, try these hands-on activities!

### Activity 1: Explore the Sensors (10 minutes)

**Goal**: Understand how physical security sensors work

**Steps**:
1. Click **"Security Center"** from the splash page
2. Click **"Door Sensor Dashboard"**
3. Watch the status display - it shows "OPEN" or "CLOSED"
4. Gently touch the door sensor (ask your facilitator where it is)
5. Watch the status change in real-time!
6. Now click **"Vibration Sensor Dashboard"**
7. Gently tap the vibration sensor
8. Watch the activity level and count increase

**What to Notice**:
- Sensors respond immediately to your touch
- The dashboard updates automatically (no refresh needed)
- Multiple vibrations trigger an alert
- The system tracks how many events occurred

**Think About**:
- How does the system know when you touch the sensor?
- Why would a bank need both door and vibration sensors?
- What happens if someone tries to break in?

---

### Activity 2: Monitor Security Events (15 minutes)

**Goal**: Act as a security guard and track events

**Steps**:
1. Open both dashboards (Door Sensor and Vibration Sensor)
2. Have a partner take turns:
   - Opening/closing the door (touching the door sensor)
   - Creating vibrations (tapping the vibration sensor)
3. You record:
   - When the door opens/closes
   - When vibrations are detected
   - When alerts are triggered
   - Total number of events

**Try This**: Switch roles - you create events while your partner monitors!

**Think About**:
- What information would be important in a real security log?
- How would you improve the alert system?
- What other sensors could be added?

---

### Activity 3: Security Scenarios (20 minutes)

**Goal**: Explore different security situations

**Try These Scenarios**:

**Scenario 1: Authorized Access**
- Touch door sensor (authorized person opens vault)
- What does the system show?
- Is there an alert?

**Scenario 2: Intrusion Attempt**
- Don't touch door sensor (door should be closed)
- Tap vibration sensor multiple times (intruder trying to break in)
- What happens after 3 vibrations?
- What alert do you see?

**Scenario 3: False Alarm**
- Touch door sensor (authorized access)
- Accidentally bump vibration sensor once
- Does it trigger an alert? Why or why not?

**Think About**:
- What's the difference between authorized access and an intrusion?
- How does the system tell them apart?
- What would happen if the sensors malfunctioned?

---

### Activity 4: Compare Cyber and Physical Security (15 minutes)

**Goal**: Understand how digital and physical security work together

**If you've tried both labs, compare them:**

**Similarities**:
- Both detect threats
- Both use sensors/patterns
- Both provide alerts
- Both need monitoring

**Differences**:
- VaultGuard AI: Digital threats, text analysis, software-based
- Security Center: Physical threats, sensor data, hardware-based

**Think About**:
- Why do banks need both digital and physical security?
- What happens if one system fails?
- How do real organizations combine these approaches?

---

## Key Concepts You're Learning

### Computer Science

As you work through the activities, you're learning:

- **Pattern Recognition**: How computers find patterns in text (VaultGuard AI) and sensor data (Security Center)
- **Rule-Based Systems**: Using rules to make decisions
- **Algorithm Tuning**: Adjusting parameters to change behavior (VaultGuard AI)
- **Data Structures**: How keywords and messages are stored (VaultGuard AI)
- **Sensor Integration**: How hardware sensors connect to software systems (Security Center)
- **Real-Time Monitoring**: Processing and displaying live data (Security Center)

### Cybersecurity

You're also exploring security concepts:

- **Phishing Detection**: How to spot suspicious messages (VaultGuard AI)
- **Threat Signals**: What makes a message dangerous (VaultGuard AI)
- **False Positives/Negatives**: Tradeoffs in security systems (both labs)
- **Defense Strategies**: Multiple layers of protection (both labs)
- **Access Control**: Monitoring who can access secure areas (Security Center)
- **Intrusion Detection**: Detecting unauthorized access attempts (Security Center)
- **Physical Security**: Protecting physical assets with sensors (Security Center)

---

## Tips & Tricks

Use these strategies to get the most out of the activity:

1. **Test Immediately**: After making changes, test them right away in the Analyzer tab
2. **Experiment**: Try extreme values - what happens if you set all scores to 50?
3. **Compare**: Work with a partner and compare your configurations
4. **Think Like a Hacker**: What would fool your detector? Try to break it!
5. **Think Like a Defender**: How can you make it better at catching threats?

---

## Troubleshooting

### Breadboard Assembly Issues

**ESP32 won't power on?**
- Check USB cable connection (both ends)
- Try a different USB port or adapter
- Make sure USB cable can carry power (some are charge-only)
- LED should light up when powered correctly

**Sensors don't work?**
- Verify all wires are connected:
  - Door sensor: VCC→3.3V, GND→GND, SIG→GPIO 14 (LEFT)
  - Vibration sensor: VCC→3.3V, GND→GND, SIG→GPIO 27 (LEFT)
- Push wires firmly into breadboard holes
- Check that wires aren't loose
- Try touching/tapping sensors more firmly

**ESP32 gets hot or smokes?**
- **Unplug immediately!**
- Check for short circuits (wires touching each other)
- Verify VCC is NOT connected to GND
- Check all connections are correct
- Ask facilitator for help before trying again

**Can't find the right pins?**
- GPIO 14 is on the LEFT side (look for "D14")
- GPIO 27 is on the LEFT side (look for "D27")
- 3.3V and GND are usually clearly labeled
- Ask your facilitator to help identify pins

**Wires keep falling out?**
- Push wires firmly into breadboard (should go in about 1/4 inch)
- Make sure wires are straight (not bent)
- Try different holes in the same row
- Ask facilitator for new wires if needed

---

### Can't connect to Wi-Fi?

If you're having trouble connecting:

- Make sure you're connected to VaultGuard-AI Wi-Fi
- Try the IP address: 192.168.4.1
- Move closer to the ESP32 device
- Wait 30 seconds after powering on ESP32
- Ask your facilitator for help

### VaultGuard AI: Changes not working?

If your customizations aren't showing up:

- Did you click "Save" after making changes?
- Try refreshing the page (browser refresh button)
- Check if you're in the right tab
- Make sure you saved each section (Keywords, Samples, Scoring, Quiz)

### Security Center: Sensors not working?

If the sensors don't respond:

- **Door sensor always shows same status**: Check with facilitator - sensor may need to be touched more firmly or wiring may need checking
- **Vibration sensor doesn't respond**: Try tapping the sensor more firmly, or ask facilitator to check wiring
- **Dashboard doesn't update**: Try refreshing the page, or check if you're on the correct dashboard
- **No sensor data at all**: Ask facilitator to check if sensors are properly connected

### Something broke?

If the system seems broken:

- **VaultGuard AI**: Use "Reset to Defaults" button in Builder tab (this only resets your changes, not the whole system)
- **Security Center**: Try refreshing the page or ask facilitator for help
- **Both**: Ask your facilitator for help

---

## Reflection Questions

After you're done customizing, think about:

1. What was the most interesting thing you learned?
2. How does changing keywords affect detection?
3. What's the hardest part about detecting phishing?
4. How would you improve this system?
5. What real-world systems work like this?

---

## Have Fun!

Remember: There's no "wrong" way to customize. Experiment, explore, and learn! The goal is to understand how cybersecurity systems work and how computer science concepts apply to real problems.

**Good luck building your perfect phishing detector!**
