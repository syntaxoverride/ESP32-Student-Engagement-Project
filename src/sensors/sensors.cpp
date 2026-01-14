#include "sensors.h"

// Static member initialization
bool SensorManager::doorInitialized = false;
bool SensorManager::vibrationInitialized = false;
unsigned long SensorManager::lastVibrationTime = 0;
int SensorManager::vibrationCount = 0;

// Interrupt-related variables (volatile because modified by ISR)
volatile bool SensorManager::vibrationTriggered = false;
volatile unsigned long SensorManager::lastInterruptTime = 0;

// Interrupt Service Routine - called instantly when pin state changes
// IRAM_ATTR keeps this in fast RAM for quick execution
void IRAM_ATTR vibrationInterruptHandler() {
  // Debounce: ignore interrupts within 50ms of each other
  unsigned long now = millis();
  if (now - SensorManager::lastInterruptTime > 50) {
    SensorManager::vibrationTriggered = true;
    SensorManager::lastInterruptTime = now;
  }
}

void SensorManager::initialize() {
  Serial.println("Initializing Security Center sensors...");
  
  // Initialize door sensor (touch switch or capacitive touch)
  if (DOOR_SENSOR_DIGITAL) {
    pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP);
    Serial.print("Door sensor (digital touch switch) initialized on GPIO ");
  } else {
    Serial.print("Door sensor (capacitive touch) initialized on GPIO ");
  }
  Serial.println(DOOR_SENSOR_PIN);
  doorInitialized = true;
  
  // Initialize vibration sensor with INTERRUPT
  // This catches brief pulses that polling would miss!
  pinMode(VIBRATION_SENSOR_PIN, INPUT_PULLUP);
  
  // Attach interrupt - fires on ANY state change (rising or falling)
  attachInterrupt(digitalPinToInterrupt(VIBRATION_SENSOR_PIN), vibrationInterruptHandler, CHANGE);
  
  vibrationInitialized = true;
  Serial.print("Vibration sensor initialized on GPIO ");
  Serial.print(VIBRATION_SENSOR_PIN);
  Serial.println(" with INTERRUPT");
  Serial.println("Using hardware interrupt to catch brief pulses!");
  Serial.print("Initial pin state: ");
  Serial.println(digitalRead(VIBRATION_SENSOR_PIN) ? "HIGH" : "LOW");
  
  // Clear any initial trigger from setup
  delay(100);
  vibrationTriggered = false;
  
  Serial.println("Security Center sensors ready!");
}

DoorData SensorManager::readDoor() {
  DoorData data;
  data.valid = false;
  data.rawValue = 0;
  data.doorOpen = false;
  
  if (!doorInitialized) {
    return data;
  }
  
  if (DOOR_SENSOR_DIGITAL) {
    int pinValue = digitalRead(DOOR_SENSOR_PIN);
    data.rawValue = pinValue;
    data.doorOpen = (pinValue == LOW); // LOW = touched = door open
  } else {
    int touchValue = touchRead(DOOR_SENSOR_PIN);
    data.rawValue = touchValue;
    data.doorOpen = (touchValue < 40);
  }
  
  data.valid = true;
  return data;
}

VibrationData SensorManager::readVibration() {
  VibrationData data;
  data.valid = false;
  data.detected = false;
  data.level = 0;
  data.alert = false;
  
  if (!vibrationInitialized) {
    return data;
  }
  
  unsigned long now = millis();
  
  // Check if interrupt was triggered since last read
  if (vibrationTriggered) {
    // Vibration detected by interrupt!
    data.detected = true;
    vibrationCount++;
    lastVibrationTime = now;
    
    // Clear the flag (but keep detecting for 2 seconds)
    vibrationTriggered = false;
    
    Serial.print("*** VIBRATION DETECTED via interrupt! Count: ");
    Serial.print(vibrationCount);
    Serial.println(" ***");
  }
  
  // Keep vibration "active" for 2 seconds after last detection
  unsigned long timeSinceVibration = now - lastVibrationTime;
  if (timeSinceVibration < 2000 && lastVibrationTime > 0) {
    data.detected = true;
    
    // Calculate decay level (100% -> 0% over 2 seconds)
    int decayLevel = 100 - (int)(timeSinceVibration / 20);
    data.level = (decayLevel > 0) ? decayLevel : 0;
  } else {
    // Reset after 2 seconds of no vibration
    if (timeSinceVibration > 2000) {
      vibrationCount = 0;
    }
    data.level = 0;
  }
  
  // Alert if multiple vibrations detected (break-in attempt)
  if (vibrationCount >= 3) {
    data.alert = true;
    data.level = 100; // Max level during alert
  }
  
  // Debug output every 30 seconds (reduced for production)
  static unsigned long lastDebugTime = 0;
  if (now - lastDebugTime > 30000) {
    Serial.print("Vibration status: count=");
    Serial.print(vibrationCount);
    Serial.print(", level=");
    Serial.print(data.level);
    Serial.print("%, alert=");
    Serial.println(data.alert ? "YES" : "no");
    lastDebugTime = now;
  }
  
  data.valid = true;
  return data;
}

int SensorManager::readDoorRaw() {
  if (DOOR_SENSOR_DIGITAL) {
    return digitalRead(DOOR_SENSOR_PIN);
  } else {
    return touchRead(DOOR_SENSOR_PIN);
  }
}
