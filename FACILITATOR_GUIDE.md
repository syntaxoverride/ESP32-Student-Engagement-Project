# Facilitator Guide: 2-Hour Web-Based Build Experience

## Overview

Everything you need to run a successful 2-hour outreach session where students customize the VaultGuard AI system through a web-based Builder interface.

## Pre-Session Setup

### Equipment Checklist

Before the session, gather the following items:

- [ ] Breadboard(s) with ESP32-WROOM already placed and firmware flashed (ESP32 pre-mounted on breadboard by developer)
- [ ] Jumper wires - at least 6 per station (male-to-male)
- [ ] Door sensor (digital touch switch module) - 1 per station
- [ ] Vibration sensor (SW-420 module) - 1 per station
- [ ] USB power adapter(s) or laptop(s) for power
- [ ] USB cables (data-capable) - 1 per station
- [ ] Wi-Fi enabled devices for students (phones/tablets/laptops)
- [ ] Optional: Projector/screen for demonstrations

### Pre-Session Testing (5 minutes)

Test the system before students arrive:

1. Power on ESP32
2. Wait 30 seconds for startup
3. Connect to `VaultGuard-AI` Wi-Fi on your phone
4. Navigate to `http://vaultguard.local` (or `http://192.168.4.1`)
5. Verify all tabs load correctly:
   - Analyzer
   - Statistics
   - Challenge
   - Learn
   - Quiz
   - Builder
6. Test facilitator reset: `http://vaultguard.local/reset`
   - Password: `RESET2025`

### Room Setup

Arrange the space for optimal connectivity:

- Position ESP32(s) centrally for good Wi-Fi coverage
- Ensure power outlets are accessible
- Have students sit within 30-50 feet of ESP32
- Test Wi-Fi signal strength in all seating areas
- Set up breadboard workstations with good lighting

---

## Breadboard Assembly (15-20 minutes)

**Objective**: Students assemble the breadboard circuit with ESP32 and sensors

**Note**: You'll guide students through building the physical circuit in this hands-on activity. Allow 15-20 minutes for assembly and testing.

### Preparation

Before starting assembly:

1. **Distribute Materials**: Give each student/pair:
   - 1 breadboard with ESP32-WROOM already placed (ESP32 is pre-mounted on breadboard)
   - 6 jumper wires (3 different colors if possible)
   - 1 door sensor (touch switch module)
   - 1 vibration sensor (SW-420 module)
   - 1 USB cable

2. **Explain Safety**:
   - "The ESP32 is already on the breadboard - don't remove it"
   - "Make sure the ESP32 is NOT powered when connecting wires"
   - "Double-check connections before powering on"
   - "If something gets hot, unplug immediately and ask for help"

3. **Show the Goal**:
   - "We're building a security system that monitors a bank vault"
   - "The door sensor detects when the vault opens"
   - "The vibration sensor detects break-in attempts"

### Step-by-Step Assembly Instructions

Walk students through these steps one at a time. Wait for everyone to complete each step before moving on.

**Note**: The ESP32 is already placed on the breadboard. Students will connect the sensors to the existing ESP32.

#### Step 1: Identify Power Pins (2 minutes)

**Instructions**:
1. "Look at your breadboard - the ESP32 is already placed on it"
2. "Find the labels on the ESP32 pins"
3. "Find the pin labeled '3V3' or '3.3V' - this is our power pin"
4. "Find the pin labeled 'GND' - this is our ground pin"
5. "There are multiple GND pins - you can use any of them"
6. "Point to these pins so I can see you found them"

**Visual Guide**:
- **3.3V**: Usually on the left side, labeled "3V3" or "3.3V"
- **GND**: Multiple locations, labeled "GND" or "G"

**What to Check**:
- Students can identify 3.3V and GND pins
- They understand these are power connections

**Common Issues**:
- **"I can't read the labels"** - Use a magnifying glass or phone camera zoom
- **"There are two 3.3V pins"** - Either one works, they're connected together
- **"I see 5V but not 3.3V"** - Look more carefully, 3.3V should be there (don't use 5V!)

---

#### Step 2: Connect Door Sensor - Power (3 minutes)

**Instructions**:
1. "Take your door sensor (touch switch module)"
2. "It has 3 wires: VCC (red), GND (black), and SIG (yellow or white)"
3. "Take a jumper wire and connect: Door Sensor VCC → ESP32 3.3V"
4. "Take another jumper wire and connect: Door Sensor GND → ESP32 GND"
5. "Double-check: Red wire to 3.3V, Black wire to GND"

**Visual Guide**:
- Door sensor typically has: VCC (red), GND (black), SIG (yellow/white/green)
- Connect VCC to 3.3V, GND to GND
- Leave SIG disconnected for now

**What to Check**:
- Red wire (VCC) goes to 3.3V
- Black wire (GND) goes to GND
- Connections are secure (not loose)

**Common Issues**:
- **"Which wire is VCC?"** - Usually red, or check the label on the sensor module
- **"The wire won't stay in"** - Make sure it's pushed all the way into the breadboard hole
- **"I'm not sure if it's connected"** - Have them show you - you should see the wire going from sensor to ESP32 pin

---

#### Step 3: Connect Door Sensor - Signal (2 minutes)

**Instructions**:
1. "Now we'll connect the signal wire"
2. "Find GPIO 14 on the LEFT side of your ESP32"
3. "Look for the label 'D14' or just '14'"
4. "Connect: Door Sensor SIG → ESP32 GPIO 14"
5. "This is the yellow or white wire"

**Visual Guide**:
- GPIO 14 is on the LEFT side of the ESP32
- Look for "D14" or "14" label
- Connect the SIG wire (usually yellow/white) to this pin

**What to Check**:
- SIG wire is connected to GPIO 14 (left side)
- Connection is secure
- Students can identify GPIO 14

**Common Issues**:
- **"I can't find GPIO 14"** - Count from the top: EN, then GPIO36, GPIO39, etc. GPIO 14 is on the left side
- **"There are two '14' pins"** - Use the one on the LEFT side, not the left
- **"The wire is loose"** - Push it in firmly

---

#### Step 4: Connect Vibration Sensor - Power (3 minutes)

**Instructions**:
1. "Take your vibration sensor (SW-420 module)"
2. "It also has 3 wires: VCC, GND, and SIG"
3. "Connect: Vibration Sensor VCC → ESP32 3.3V"
4. "Connect: Vibration Sensor GND → ESP32 GND"
5. "You can use the same 3.3V and GND pins - they can share power"

**Visual Guide**:
- Vibration sensor wires: VCC (red), GND (black), SIG (yellow/white)
- Can share the same 3.3V and GND pins as the door sensor

**What to Check**:
- Both sensors have power connected
- GND connections are secure
- No wires are crossed

**Common Issues**:
- **"Can I use the same power pins?"** - Yes! Multiple devices can share power
- **"The breadboard is getting crowded"** - That's normal, just make sure wires don't touch each other
- **"I'm not sure which wire is which"** - Check the labels on the sensor module

---

#### Step 5: Connect Vibration Sensor - Signal (2 minutes)

**Instructions**:
1. "Now connect the vibration sensor signal wire"
2. "Find GPIO 27 on the LEFT side of your ESP32"
3. "Look for the label 'D27' or '27'"
4. "Connect: Vibration Sensor SIG → ESP32 GPIO 27"
5. "This is the yellow or white wire from the vibration sensor"

**Visual Guide**:
- GPIO 27 is on the LEFT side of the ESP32
- Look for "D27" or "27" label
- Connect the SIG wire to this pin

**What to Check**:
- SIG wire is connected to GPIO 27 (left side)
- This is different from GPIO 14 (door sensor)
- Connection is secure

**Common Issues**:
- **"I can't find GPIO 27"** - It's on the LEFT side, count down from EN
- **"I connected it to the wrong pin"** - Both sensors are on the LEFT side: GPIO 14 (door) and GPIO 27 (vibration)
- **"The wires look the same"** - Use different colored wires if possible, or label them

---

#### Step 6: Final Check (2 minutes)

**Instructions**:
1. "Before we power on, let's check all connections"
2. "Door Sensor: VCC → 3.3V, GND → GND, SIG → GPIO 14 (LEFT)"
3. "Vibration Sensor: VCC → 3.3V, GND → GND, SIG → GPIO 27 (LEFT)"
4. "Make sure no wires are touching each other"
5. "Make sure no wires are loose"

**Connection Checklist**:
- [ ] Door sensor VCC → 3.3V
- [ ] Door sensor GND → GND
- [ ] Door sensor SIG → GPIO 14 (LEFT side)
- [ ] Vibration sensor VCC → 3.3V
- [ ] Vibration sensor GND → GND
- [ ] Vibration sensor SIG → GPIO 27 (LEFT side)
- [ ] No loose wires
- [ ] No wires touching each other

**What to Check**:
- All 6 connections are correct
- No short circuits (wires touching)
- Everything is secure

---

#### Step 7: Power On and Test (3 minutes)

**Instructions**:
1. "Now we'll power on the ESP32"
2. "Connect your USB cable to the ESP32"
3. "Connect the other end to a USB power adapter or laptop"
4. "Watch for a small LED to light up on the ESP32"
5. "Wait 30 seconds for the system to start"
6. "The LED should be on - this means it's working"

**What to Look For**:
- LED lights up on ESP32
- No smoke or burning smell (if you see this, unplug immediately!)
- ESP32 feels normal temperature (not hot)

**Testing the Sensors**:
1. "Once the LED is on, we can test the sensors"
2. "Gently touch the door sensor - you should feel a click"
3. "Tap the vibration sensor gently"
4. "We'll verify these work in the web interface"

**Common Issues**:
- **"LED doesn't light up"** - Check USB connection, try different USB port/cable
- **"ESP32 gets hot"** - Unplug immediately! There's a short circuit - check wiring
- **"Nothing happens"** - Make sure USB cable can carry power (some are charge-only)

---

### Breadboard Assembly Troubleshooting

#### Problem: ESP32 won't power on

**What to check**:
1. USB cable is properly connected (both ends)
2. USB power source is working (try different port/adapter)
3. USB cable can carry power (not all cables work - try a different one)
4. ESP32 LED should light up when powered

**If still not working**:
- Try a different USB cable
- Try a different power source (laptop USB port, wall adapter)
- Check if ESP32 LED lights up at all
- If LED never lights, ESP32 may be damaged - contact technical support

---

#### Problem: Sensors don't respond

**What to check first**:
1. **Power connections**: Both sensors need VCC → 3.3V and GND → GND
2. **Signal connections**: Door sensor SIG → GPIO 14 (LEFT), Vibration sensor SIG → GPIO 27 (LEFT)
3. **Wires are secure**: Push wires firmly into breadboard holes
4. **No loose connections**: Gently tug wires to verify they're connected

**If door sensor doesn't work**:
- Verify SIG wire is on GPIO 14 (LEFT side), not GPIO 27
- Check that VCC and GND are connected
- Try touching the sensor more firmly
- Check if wire is loose in breadboard

**If vibration sensor doesn't work**:
- Verify SIG wire is on GPIO 27 (LEFT side), not GPIO 14
- Check that VCC and GND are connected
- Try tapping sensor more firmly
- Vibration sensor needs movement - try shaking it gently

---

#### Problem: ESP32 gets hot or smokes

**STOP IMMEDIATELY**:
1. **Unplug USB cable right away**
2. **Do not touch the ESP32** - it may be hot
3. **Check for short circuits**:
   - Are any wires touching each other?
   - Is VCC connected to GND by mistake?
   - Are wires in the wrong pins?

**Common causes**:
- VCC connected to GND (power short circuit)
- Wires touching each other
- Wrong pin connections
- Damaged sensor module

**After fixing**:
- Double-check all connections
- Make sure no wires are touching
- Verify VCC goes to 3.3V, GND goes to GND
- Try powering on again carefully

---

#### Problem: Wrong pin connections

**How to identify**:
- Door sensor should be on GPIO 14 (LEFT side)
- Vibration sensor should be on GPIO 27 (LEFT side)
- Both sensors share 3.3V and GND

**How to fix**:
1. Unplug ESP32 (always unplug before changing wiring!)
2. Check which sensor is on which pin
3. Move wires to correct pins:
   - Door sensor SIG → GPIO 14 (LEFT)
   - Vibration sensor SIG → GPIO 27 (LEFT)
4. Re-check all connections
5. Power on and test

---

#### Problem: Wires keep falling out

**Solutions**:
- Push wires firmly into breadboard holes (should go in about 1/4 inch)
- Make sure wires are straight (not bent)
- Use fresh jumper wires (old ones may be loose)
- Check that breadboard holes aren't damaged
- Try different holes in the same row (breadboard rows are connected)

---

#### Problem: Can't identify ESP32 pins

**Tips**:
- Use a magnifying glass or phone camera zoom
- Look for labels like "D14", "D27", "3V3", "GND"
- Count pins from the top (EN is usually at the top)
- GPIO 14 is on LEFT side, GPIO 27 is on LEFT side
- 3.3V and GND are usually clearly labeled

**Visual reference**:
- Left side: 3.3V, GND, GPIO 15, GPIO 2, **GPIO 14** (door sensor)
- Left side: EN, GPIO 36, GPIO 39, ..., **GPIO 27** (vibration sensor)

---

### Post-Assembly Verification

After assembly, verify everything works:

1. **Power Check**: ESP32 LED is on
2. **Door Sensor Test**: Touch door sensor - status should change in web interface
3. **Vibration Sensor Test**: Tap vibration sensor - activity should register
4. **Web Interface**: Connect to Wi-Fi and check Security Center dashboards

**If everything works**: Great! Move on to the web interface activities.

**If something doesn't work**: Use troubleshooting guide above, or ask for help.

---

## Session Flow (2 Hours)

### Phase 1: Exploration & Understanding (25 minutes)

**Objective**: Students explore both labs and understand how they work

**Activities**:

1. **Introduction (5 min)**
   - Welcome and explain the activity
   - "Today you'll work with two security systems: an AI phishing detector and a bank vault monitoring system"
   - "Everything is web-based - no coding required!"
   - "You can choose which lab to explore first, or try both!"

2. **Connection (5 min)**
   - "Connect to Wi-Fi: VaultGuard-AI"
   - "Open browser to vaultguard.local or 192.168.4.1"
   - Help students who have connection issues
   - "You'll see a splash page with two options: VaultGuard AI and Security Center"

3. **Exploration (15 min)**

   **Option A: VaultGuard AI (AI Phishing Detector)**
   - Guide students through tabs:
     - **Analyzer**: Try sample messages, see how scoring works
     - **Statistics**: View patterns in detected signals
     - **Challenge**: Try to fool the detector
     - **Learn**: Read about phishing patterns
     - **Quiz**: Test cybersecurity knowledge
     - **Builder**: Customize the system
   - **Key Discussion Points**:
     - "How does the detector decide if something is suspicious?"
     - "What patterns do you notice in the sample messages?"
     - "Why might some messages score higher than others?"

   **Option B: Security Center (Bank Vault Monitoring)**
   - Guide students through the Security Center:
     - **Door Sensor Dashboard**: Shows door open/closed status in real-time
     - **Vibration Sensor Dashboard**: Detects and displays intrusion attempts
     - **Status Indicators**: Visual feedback for vault security state
   - **Key Discussion Points**:
     - "How does the system know if the door is open or closed?"
     - "What happens when the vibration sensor detects movement?"
     - "How would this work in a real bank vault?"
     - "What other sensors could be added to improve security?"

**Facilitator Notes**:
- Walk around and help students connect
- Let students choose which lab interests them most
- Some students may want to explore both labs
- Point out the engaging UI design
- Encourage experimentation in both labs

**What to Look For - VaultGuard AI**:
- Students should see risk scores (0-100%) for each message
- "Safe" messages score below 60%, "Suspicious" messages score above 60%
- Each analysis shows detected signals (urgency, links, etc.)
- Statistics tab shows patterns across all analyzed messages

**What to Look For - Security Center**:
- Door sensor shows "OPEN" or "CLOSED" status
- Vibration sensor shows activity level and count
- Status changes update in real-time on the dashboard
- Students can physically interact with sensors (touch door sensor, tap vibration sensor)

**Common Questions & Answers - VaultGuard AI**:
- **"Why does this message say 'Safe' but has a score?"** - Even safe messages can have some suspicious elements, but not enough to trigger the threshold.
- **"What do the percentages mean?"** - Higher percentage = more suspicious. The system adds up points from different signals.
- **"Can I analyze my own message?"** - Yes! Type or paste any message in the Analyzer tab.

**Common Questions & Answers - Security Center**:
- **"How does the door sensor work?"** - It uses capacitive touch sensing - when you touch the sensor, it detects the change and reports the door as "open."
- **"What triggers the vibration sensor?"** - Any movement or vibration near the sensor will trigger it. Try tapping the sensor gently.
- **"Why does it say 'BREACH DETECTED'?"** - After 3 vibration detections, the system assumes an intrusion attempt and alerts.
- **"Can I see historical data?"** - The dashboard shows current status and recent activity counts.

---

### Phase 2: Basic Customization (30 minutes)

**Objective**: Students modify keywords and create sample messages

**Activities**:

1. **Introduction to Builder Tab (5 min)**
   - Show students the Builder tab
   - Explain: "This is where you customize the system"
   - Walk through the sections:
     - Keywords Manager
     - Sample Messages
     - Scoring Weights
     - Quiz Builder

2. **Challenge 1: Add Keywords (10 min)**

   **Task**: "Add 3 new keywords to the Urgency category"
   
   **Step-by-Step Instructions**:
   1. Click on the **Builder** tab at the top
   2. Find the **Keywords Manager** section
   3. Look for the dropdown that says "Select Category" - click it
   4. Select **"Urgency Language"** from the list
   5. In the text box below, type a keyword (e.g., "emergency", "critical", "urgent", "asap")
   6. Click the **"Add"** button next to the text box
   7. The keyword should appear in the list below
   8. Repeat steps 5-7 to add 2 more keywords
   9. Scroll down and click the **"Save Keywords"** button
   10. You should see a confirmation message
   
   **Testing the Changes**:
   1. Go to the **Analyzer** tab
   2. Type a test message like: "This is an emergency! Click here now!"
   3. Click **"Analyze Message"**
   4. The message should score higher than before because it contains your new keyword
   
   **Expected Outcome**:
   - Students should see their keywords appear in the list
   - Messages containing their keywords should score higher
   - The system detects keywords regardless of capitalization
   
   **Good Keyword Examples**:
   - Urgency: "emergency", "critical", "urgent", "asap", "immediately", "now"
   - Credentials: "password", "login", "verify", "account", "username"
   - Rewards: "prize", "winner", "congratulations", "free", "bonus"
   - Financial: "payment", "invoice", "overdue", "charge", "fee"
   
   **Troubleshooting**:
   - **"My keyword didn't appear in the list"** - Make sure you clicked "Add" after typing, not just "Save Keywords"
   - **"The message still scores the same"** - Make sure you clicked "Save Keywords" and the message actually contains your keyword
   - **"I can't find the Keywords Manager"** - Make sure you're in the Builder tab, not another tab
   
   **Discussion Prompts**:
   - "How did adding keywords change the detection?"
   - "Why do you think urgency words are suspicious?"
   - "What other words might phishers use to create urgency?"
   - "What happens if you add a common word like 'the' or 'and'?" (It will flag too many messages - good learning moment!)

3. **Challenge 2: Create Sample Messages (15 min)**

   **Task**: "Create 2 custom sample messages - one safe, one suspicious"
   
   **Step-by-Step Instructions**:
   1. Stay in the **Builder** tab
   2. Scroll down to the **Sample Messages** section
   3. In the large text box, type your first message
   4. Click the **"Add"** button
   5. The message should appear in the list below
   6. Clear the text box and type your second message
   7. Click **"Add"** again
   8. Scroll down and click **"Save Samples"** button
   9. You should see a confirmation message
   
   **Testing the Changes**:
   1. Go to the **Analyzer** tab
   2. Your custom messages should appear as clickable chips at the top
   3. Click on one of your messages
   4. Click **"Analyze Message"** to see how it scores
   
   **Expected Outcome**:
   - Custom messages appear as chips in the Analyzer tab
   - Students can click their chips to analyze them
   - Safe messages should score below 60%, suspicious ones above 60%
   
   **Good Message Examples**:
   
   **Safe Message Example**:
   - "Hi, just wanted to check in about the meeting tomorrow. Let me know if 3pm works for you. Thanks!"
   - Why it's safe: No urgency, no links, no credential requests, friendly tone
   
   **Suspicious Message Example**:
   - "URGENT: Your account will be suspended in 24 hours! Click here to verify: http://verify-account-now.com/login"
   - Why it's suspicious: Urgency language, suspicious link, credential request
   
   **Tricky Message Example** (for advanced students):
   - "Congratulations! You've won a $500 gift card. Reply with your email to claim your prize."
   - Why it's tricky: Looks like good news, but contains reward bait and credential request
   
   **Troubleshooting**:
   - **"My message didn't appear as a chip"** - Make sure you clicked "Add" and then "Save Samples"
   - **"I can't see my messages"** - Refresh the Analyzer tab or navigate away and back
   - **"My safe message scored high"** - That's okay! Discuss why - maybe it has some suspicious elements
   
   **Discussion Prompts**:
   - "What makes a good test message?"
   - "Why is it important to test with both safe and suspicious messages?"
   - "What patterns do you notice in the suspicious messages?"
   - "How would a real phisher try to trick people?"

**Facilitator Notes**:
- Encourage creativity in keyword selection
- Help students understand the connection between keywords and detection
- Have students test their changes immediately
- Point out that changes are instant - no compilation needed!
- If a student's "safe" message scores high, use it as a teaching moment about false positives

---

### Phase 3: Advanced Customization (40 minutes)

**Objective**: Students understand algorithm tuning and tradeoffs

**Activities**:

1. **Challenge 3: Adjust Scoring (20 min)**

   **Task**: "Make the detector more sensitive, then less sensitive"
   
   **Step-by-Step Instructions - Part 1: More Sensitive**:
   1. Go to **Builder** tab → **Scoring Weights** section
   2. You'll see several categories with number values (like "Urgency Language: 15", "Suspicious Links: 20", etc.)
   3. Increase each number by 5 points (e.g., if it says 15, change it to 20)
   4. Scroll down and click **"Save Scoring"**
   5. Go to **Analyzer** tab
   6. Test with a message that was previously "Safe" - it might now be "Suspicious"
   
   **Step-by-Step Instructions - Part 2: Less Sensitive**:
   1. Go back to **Builder** tab → **Scoring Weights**
   2. Decrease each number by 10 points from the original (e.g., if original was 15, make it 5)
   3. Click **"Save Scoring"**
   4. Go to **Analyzer** tab
   5. Test with a message that was previously "Suspicious" - it might now be "Safe"
   
   **Expected Outcome**:
   - Higher scores = more messages flagged as suspicious (more sensitive)
   - Lower scores = fewer messages flagged (less sensitive)
   - Students should see the same message get different verdicts
   
   **What Students Should Notice**:
   - When scores are higher: More messages are flagged, including some that might be safe (false positives)
   - When scores are lower: Fewer messages are flagged, including some that might be dangerous (false negatives)
   - The threshold is 60% - messages above 60% are "Suspicious", below are "Safe"
   
   **Real-World Connection**:
   - Email filters work the same way - too sensitive = too many false alarms
   - Too lenient = dangerous emails get through
   - Security systems must balance these tradeoffs
   
   **Troubleshooting**:
   - **"Nothing changed"** - Make sure you clicked "Save Scoring" and the numbers actually changed
   - **"I can't find Scoring Weights"** - It's in the Builder tab, scroll down past Keywords and Sample Messages
   - **"The numbers won't change"** - Make sure you're typing in the input boxes, not just looking at them
   
   **Discussion Points**:
   - "What happened when you increased the weights?"
   - "What's the tradeoff between catching more vs. fewer messages?"
   - "What's a false positive? False negative?"
   - "If you were running an email system, would you rather have false positives or false negatives? Why?"
   - "How do real security systems handle this problem?"
   
   **Extension Activity**:
   - Challenge students to find the "perfect" balance
   - Have them test with 5 different messages
   - See if they can catch all suspicious messages without flagging safe ones
   - Discuss why this is hard!

2. **Challenge 4: Add Quiz Question (20 min)**

   **Task**: "Create a quiz question about a phishing technique"
   
   **Step-by-Step Instructions**:
   1. Go to **Builder** tab → **Quiz Builder** section
   2. In the "Question" text box, type your question (e.g., "What is a common sign of a phishing email?")
   3. In the "Option A" text box, type the first answer choice
   4. In "Option B", type the second choice
   5. In "Option C", type the third choice
   6. In "Option D", type the fourth choice
   7. Below the options, select which letter is the correct answer (A, B, C, or D)
   8. Click **"Add Question"** button
   9. Your question should appear in the list below
   10. Scroll down and click **"Save Quiz"** button
   11. You should see a confirmation message
   
   **Testing the Changes**:
   1. Go to the **Quiz** tab
   2. Your question should appear in the quiz
   3. Try answering it to make sure it works
   
   **Expected Outcome**:
   - Custom question appears in the Quiz tab
   - Students can select an answer and see if they're correct
   - The quiz shows correct/incorrect feedback
   
   **Good Question Examples**:
   
   **Question 1**:
   - Question: "What should you do if you receive a suspicious email asking for your password?"
   - A) Reply with your password immediately
   - B) Click any links in the email
   - C) Delete the email and report it
   - D) Forward it to all your friends
   - Correct Answer: C
   
   **Question 2**:
   - Question: "Which of these is a red flag for phishing?"
   - A) Professional email formatting
   - B) Urgent language demanding immediate action
   - C) Clear sender information
   - D) Links to official websites
   - Correct Answer: B
   
   **Question 3**:
   - Question: "What is 'spear phishing'?"
   - A) Fishing with a spear
   - B) Phishing targeted at specific individuals
   - C) A type of computer virus
   - D) A secure email protocol
   - Correct Answer: B
   
   **Troubleshooting**:
   - **"My question didn't appear"** - Make sure you clicked "Add Question" and then "Save Quiz"
   - **"I can't select the correct answer"** - Make sure you selected A, B, C, or D from the dropdown before clicking "Add Question"
   - **"The quiz looks wrong"** - Make sure you filled in all four answer options (A, B, C, D)
   
   **Discussion Prompts**:
   - "What makes a good quiz question?"
   - "Why is it important to test cybersecurity knowledge?"
   - "What did you learn from creating your own question?"
   - "How do companies train employees to spot phishing?"

**Facilitator Notes**:
- This is where CS concepts really shine
- Emphasize the tradeoffs in algorithm design
- Connect to real-world: "How do security systems balance sensitivity?"
- Encourage experimentation - there's no "wrong" answer
- If students struggle with scoring, help them understand: higher numbers = more sensitive
- Use the quiz creation as a way to reinforce what they've learned

---

### Phase 4: Integration & Showcase (25 minutes)

**Objective**: Students synthesize their learning and share

**Activities**:

1. **Challenge 5: Complete Configuration (15 min)**

   **Task**: "Create your perfect phishing detector"
   
   **Checklist for Students**:
   - [ ] Added custom keywords in at least 3 different categories
   - [ ] Created at least 3 custom sample messages (mix of safe and suspicious)
   - [ ] Adjusted scoring weights to their preferred sensitivity level
   - [ ] Created at least 2 custom quiz questions
   
   **Testing Everything**:
   1. Go to **Analyzer** tab - test your custom sample messages
   2. Check **Statistics** tab - see patterns in detected signals
   3. Try **Challenge** mode - see if you can fool your own detector
   4. Go to **Quiz** tab - take your own quiz questions
   5. Verify everything works as expected
   
   **What Makes a "Perfect" Detector**:
   - Catches obvious phishing attempts
   - Doesn't flag too many safe messages
   - Has relevant keywords for current threats
   - Includes educational quiz questions
   - Balanced scoring that works for different message types
   
   **Facilitator Guidance**:
   - Walk around and check on student progress
   - Help students who are stuck
   - Encourage them to test thoroughly
   - Remind them there's no single "right" answer - different approaches are valid
   
   **Common Issues**:
   - **"I forgot what I changed"** - That's okay! Have them test and see what works
   - **"Nothing seems to work"** - Make sure they saved each section (Keywords, Samples, Scoring, Quiz)
   - **"My detector flags everything"** - Help them lower the scoring weights
   - **"My detector misses obvious phishing"** - Help them raise the scoring weights or add more keywords

2. **Sharing & Presentation (10 min)**

   **Sharing Format**:
   - Have students share their configurations with neighbors or in small groups
   - Ask each student (or pair) to explain:
     - What they changed and why
     - What was most interesting
     - What they learned
     - How they would improve it further
   
   **Discussion Prompts**:
   - "What did you change and why?"
   - "What was the most interesting thing you learned?"
   - "How did your approach differ from others?"
   - "What makes an effective phishing detector?"
   - "What would you add or change if you had more time?"
   
   - **Compare Different Approaches**:
     - Some students might prefer high sensitivity (catch everything)
     - Others might prefer balanced (fewer false alarms)
     - Discuss the pros and cons of each approach
     - Connect to real-world security systems
   
   **Key Takeaways to Reinforce**:
   - Pattern recognition is a key CS concept
   - Algorithm tuning requires balancing tradeoffs
   - Security systems need constant adjustment
   - No system is perfect - defense in depth is important
   - Human judgment is still crucial

**Facilitator Notes**:
- Create a positive, sharing environment
- Highlight different creative approaches
- Connect back to cybersecurity concepts
- Ask: "How would you improve this system further?"
- Celebrate different solutions - there's no single right answer
- Use this time to reinforce key concepts from the session

---

## Security Center Activities (Alternative/Additional Track)

**Note**: Students can explore the Security Center alongside or instead of the VaultGuard AI activities. The Security Center focuses on physical security sensors and real-time monitoring.

### Security Center Overview

The Security Center simulates a bank vault monitoring system with two sensors:
- **Door Sensor** (Touch sensor on GPIO 14): Detects when the vault door is opened or closed
- **Vibration Sensor** (SW-420 on GPIO 27): Detects movement and potential intrusion attempts

### Activity 1: Exploring the Security Center (10 minutes)

**Objective**: Students understand how physical security sensors work

**Step-by-Step Instructions**:
1. From the splash page, click **"Security Center"**
2. Students will see a menu with two options:
   - **Door Sensor Dashboard**
   - **Vibration Sensor Dashboard**
3. Click on **"Door Sensor Dashboard"**
4. Observe the real-time status display
5. Have students gently touch the door sensor (GPIO 14) and watch the status change
6. Click on **"Vibration Sensor Dashboard"**
7. Have students gently tap the vibration sensor and observe the activity

**Expected Outcome**:
- Door sensor shows "OPEN" when touched, "CLOSED" when not touched
- Vibration sensor shows activity level and count
- Status updates happen in real-time (no page refresh needed)
- After 3 vibrations, system shows "BREACH DETECTED" alert

**What Students Should Notice**:
- Sensors respond immediately to physical interaction
- The dashboard updates automatically
- Multiple vibrations trigger an alert
- The system tracks activity counts

**Discussion Points**:
- "How does the door sensor know when it's touched?"
- "Why would a bank vault need a vibration sensor?"
- "What happens if someone tries to break in?"
- "How is this different from the VaultGuard AI's detection system?"

### Activity 2: Monitoring Security Events (15 minutes)

**Objective**: Students observe and document security events

**Task**: "Monitor the vault and record what happens"

**Instructions**:
1. Open both dashboards (Door Sensor and Vibration Sensor)
2. Have one student act as a "security guard" monitoring the system
3. Have other students take turns:
   - Opening/closing the door (touching the door sensor)
   - Creating vibrations (tapping the vibration sensor)
4. The "security guard" records:
   - When the door opens/closes
   - When vibrations are detected
   - When alerts are triggered
   - How many events occurred

**Expected Outcome**:
- Students see real-time monitoring in action
- They understand how security systems track events
- They learn about event logging and alerting

**Discussion Points**:
- "What information would be important to log in a real security system?"
- "How would you improve the alert system?"
- "What other sensors could be added?"
- "How do real banks monitor their vaults?"

### Activity 3: Security Scenarios (20 minutes)

**Objective**: Students explore different security scenarios

**Scenarios to Try**:

**Scenario 1: Authorized Access**
- Touch door sensor (authorized person opens vault)
- System should show "ACCESS GRANTED"
- No vibration detected
- Status: Normal operation

**Scenario 2: Intrusion Attempt**
- Don't touch door sensor (door should be closed)
- Tap vibration sensor multiple times (intruder trying to break in)
- System should show "BREACH DETECTED" after 3 vibrations
- Status: Alert triggered

**Scenario 3: False Alarm**
- Touch door sensor (authorized access)
- Accidentally bump vibration sensor once
- System should show door open but no breach alert
- Status: Normal (single vibration doesn't trigger alert)

**Discussion Points**:
- "What's the difference between authorized access and an intrusion?"
- "How does the system distinguish between normal operation and threats?"
- "What would happen if the sensors malfunctioned?"
- "How do real security systems handle false alarms?"

### Activity 4: Comparing Cyber and Physical Security (15 minutes)

**Objective**: Students understand the relationship between digital and physical security

**Task**: "Compare the VaultGuard AI and Security Center"

**Comparison Questions**:
1. How are they similar?
   - Both detect threats
   - Both use sensors/patterns
   - Both provide alerts
   - Both need tuning

2. How are they different?
   - VaultGuard AI: Digital threats, text analysis, software-based
   - Security Center: Physical threats, sensor data, hardware-based

3. How do they work together?
   - Defense in depth: multiple layers of security
   - Both protect valuable assets
   - Both need monitoring and response

**Discussion Points**:
- "Why do banks need both digital and physical security?"
- "What happens if one system fails?"
- "How do real organizations combine these approaches?"
- "What other types of security systems exist?"

**Facilitator Notes for Security Center**:
- Walk around and help students interact with sensors
- Ensure sensors are properly connected (check wiring if needed)
- Encourage students to experiment with different scenarios
- Connect to real-world security systems
- Some students may prefer hands-on sensor activities over text analysis
- If sensors aren't working, check connections and refer to troubleshooting section

**Troubleshooting - Security Center**:
- **"Door sensor always shows OPEN"** - Check wiring on GPIO 14, ensure sensor is properly connected
- **"Vibration sensor doesn't respond"** - Check wiring on GPIO 27, try tapping sensor more firmly
- **"Dashboard doesn't update"** - Refresh the page, check browser console for errors
- **"Sensors not detected"** - Verify ESP32 is powered on, check Serial Monitor for sensor initialization messages

---

## Key Discussion Prompts

### Computer Science Concepts

Use these prompts to guide discussions:

- **Pattern Recognition**: "How does the system recognize patterns in text?" 
  - *Explanation*: The system looks for specific words and phrases that appear in phishing emails. It's like teaching a computer to recognize patterns, similar to how you recognize a friend's face.
  
- **Rule-Based Systems**: "What rules does the classifier use?"
  - *Explanation*: The system uses rules like "if message contains urgency words, add points" or "if message has suspicious links, add more points." These rules combine to make a decision.
  
- **Algorithm Tuning**: "How do you balance sensitivity vs. accuracy?"
  - *Explanation*: Adjusting the "knobs" (scoring weights) makes the system more or less sensitive. Too sensitive = too many false alarms. Too lenient = dangerous emails get through.
  
- **Data Structures**: "How are keywords stored and searched?"
  - *Explanation*: Keywords are stored in lists by category. When analyzing a message, the system searches through these lists to find matches. Searching through lists is a fundamental CS concept.

### Cybersecurity Concepts

Explore these security topics:

- **Phishing Techniques**: "What tactics do phishers use?"
  - *Common tactics*: Urgency, impersonation, reward bait, credential requests, suspicious links, financial pressure
  
- **Defense in Depth**: "Why is pattern detection just one layer?"
  - *Explanation*: No single security measure is perfect. Real systems use multiple layers: pattern detection, link checking, sender verification, user training, etc.
  
- **False Positives/Negatives**: "What are the tradeoffs?"
  - *False Positive*: Safe message flagged as suspicious (annoying but safe)
  - *False Negative*: Dangerous message missed (dangerous!)
  - *Tradeoff*: Can't eliminate both - must choose balance
  
- **Social Engineering**: "How do phishers manipulate people?"
  - *Explanation*: Phishers use psychology - urgency, fear, greed, authority - to trick people into making mistakes.

### Real-World Connections

Connect to actual systems:

- "How do email filters work?" - They use similar pattern recognition and scoring systems
- "Why do security systems need tuning?" - Threats evolve, so systems must adapt
- "What happens when a system is too sensitive?" - Users get frustrated with false alarms and may disable it
- "How do companies train employees to spot phishing?" - Education + technology = best defense

---

## Troubleshooting

### Problem: Students can't connect to Wi-Fi

**What to check first**:
- Verify ESP32 is powered on (LED should be on)
- Wait 30 seconds after powering on for full startup
- Move closer to ESP32 (range is ~30-50 feet)
- Try restarting ESP32 (unplug and replug power)

**If still not working**:
- Use IP address: 192.168.4.1 instead of vaultguard.local
- Check if Wi-Fi network name matches: `VaultGuard-AI` (or `VaultGuard-AI 1`, etc. if customized)
- Try a different device to test if it's device-specific

### Problem: Builder changes don't work

**Quick fixes**:
- Verify "Save" button was clicked after making changes
- Try refreshing the page (browser refresh button)
- Check if student is in the correct tab (Builder tab)
- Have student try a different browser

**Common Mistakes**:
- Students forget to click "Save" after making changes
- Students are in the wrong tab (e.g., Analyzer instead of Builder)
- Browser cache issues - try hard refresh (Ctrl+F5 or Cmd+Shift+R)

### Problem: Portal doesn't open automatically

**Solutions**:
- Manually navigate to vaultguard.local or 192.168.4.1
- Clear browser cache (or try incognito/private mode)
- Try different browser (Chrome, Safari, Firefox)
- Some devices don't support `.local` domains - always use IP address as backup

### Problem: Too many students, system slow

**Solutions**:
- Limit to 20-30 simultaneous connections per ESP32
- Use multiple ESP32s if needed (each creates its own network)
- Have students work in pairs to reduce connections
- Stagger activities so not everyone is on the same tab at once

### Problem: System seems frozen or unresponsive

**Solutions**:
- Try the facilitator reset (see Facilitator Reset section below)
- Power cycle the ESP32 (unplug, wait 10 seconds, replug)
- If persistent, contact technical support - may need firmware re-flash

### Problem: Student's changes disappeared

**Solutions**:
- Changes are stored in memory and reset when ESP32 restarts
- This behavior is intentional - it allows experimentation without permanent changes
- If students want to keep changes, they should document them
- Use facilitator reset between groups to ensure clean slate

---

## Facilitator Reset

### When to Reset

Reset the system in these situations:

- Between groups/sessions
- If system gets into a bad state
- At the end of the day
- If students have made too many experimental changes

### How to Reset

Follow these steps:

1. Navigate to: `http://vaultguard.local/reset` (or `http://192.168.4.1/reset`)
2. Enter password: `RESET2025`
3. Click "RESET SYSTEM"
4. Wait for confirmation message
5. System is ready for next group

**Note**: The reset URL is hidden from students - it's not visible in the Builder tab or main navigation.

### What Gets Reset

The reset function restores everything to defaults:

- All keywords → defaults
- All sample messages → defaults
- All scoring weights → defaults
- All quiz questions → defaults
- Statistics counters → zero
- Challenge stats → zero

**Note**: Reset is password-protected to prevent accidental resets by students.

---

## Tips for Success

Follow these recommendations for smooth sessions:

1. **Be Enthusiastic**: The cyberpunk UI is designed to be cool - lean into it!
2. **Encourage Experimentation**: There's no "wrong" way to customize
3. **Connect to Real World**: Always tie back to actual cybersecurity
4. **Let Students Lead**: They'll discover things you didn't expect
5. **Time Management**: Don't rush, but keep an eye on the clock
6. **Have Backup Ready**: Keep a spare ESP32 ready if possible
7. **Walk Around**: Check on students regularly, especially during challenges
8. **Celebrate Mistakes**: When something doesn't work as expected, use it as a learning moment

---

## Post-Session

### Cleanup

After each session:

1. Reset all ESP32s using facilitator reset
2. Power down devices
3. Document any issues encountered
4. Note what worked well for next time

### Reflection Questions (Optional)

Consider these questions after the session:

- What was most engaging for students?
- What concepts were hardest to grasp?
- What would you change for next time?
- Did students understand the CS/cybersecurity connections?
- Which challenges worked best?
- What questions did students ask most often?

---

## Quick Reference

### Access URLs

Keep these handy during the session:

- Main Portal: `http://vaultguard.local` or `http://192.168.4.1`
- Facilitator Reset: `http://vaultguard.local/reset` (hidden URL)
- Password: `RESET2025`

### Wi-Fi Network

Network details:

- SSID: `VaultGuard-AI` (or `VaultGuard-AI 1`, `VaultGuard-AI 2`, etc. if customized)
- Password: None (open network)

### Session Timing

Phase breakdown:

- Phase 1: 25 min
- Phase 2: 30 min
- Phase 3: 40 min
- Phase 4: 25 min
- **Total: 120 minutes (2 hours)**

### Lab Overview

Help students navigate:

**VaultGuard AI (AI Phishing Detector)**:
- **Analyzer**: Test messages and see risk scores
- **Statistics**: View patterns across all analyzed messages
- **Challenge**: Try to create messages that fool the detector
- **Learn**: Read about phishing techniques and cybersecurity
- **Quiz**: Test knowledge with multiple choice questions
- **Builder**: Customize keywords, samples, scoring, and quiz questions

**Security Center (Bank Vault Monitoring)**:
- **Door Sensor Dashboard**: Real-time door open/closed status
- **Vibration Sensor Dashboard**: Intrusion detection and activity monitoring
- **Live Updates**: Both dashboards update automatically without refresh
- **Security Alerts**: System triggers "BREACH DETECTED" after 3 vibrations

---

## Support

### When to Contact Technical Support

Contact your technical support person in these situations:

- ESP32 won't power on or LED doesn't light up
- Wi-Fi network doesn't appear after 30 seconds
- System consistently freezes or crashes
- Multiple students report the same persistent error
- Portal won't load even after trying all troubleshooting steps
- You need to re-flash firmware (this requires VS Code and developer setup)

### What Information to Provide

When contacting support, include:

- What you were doing when the problem occurred
- What error messages (if any) students see
- How many students are connected
- Whether the problem affects all students or just some
- What troubleshooting steps you've already tried
- ESP32 station number (if using multiple units)

### Emergency Procedures

If the system completely fails during a session:

1. **Don't panic** - students can still learn from the experience
2. Try power cycle (unplug, wait 10 seconds, replug)
3. If that doesn't work, try facilitator reset
4. If still not working, switch to backup ESP32 if available
5. As last resort, use the time for discussion about what went wrong and why - turn it into a learning opportunity about system reliability

### Getting Help

**Before the session**: Make sure you have contact information for your technical support person. They should be available during your session time.

**During the session**: If possible, have technical support on standby for the first session. After that, you'll know the common issues.

**After the session**: Document any problems so they can be addressed before the next session.

---

**Remember**: The system is designed to be robust and plug-and-play. Most issues can be resolved with a simple power cycle or reset. Stay calm, use the reset function, and keep the session moving!
