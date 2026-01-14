#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// Pin definitions - SECURITY CENTER
#define DOOR_SENSOR_PIN 4         // Touch switch / door sensor (GPIO 4) - Right side
#define VIBRATION_SENSOR_PIN 27   // Vibration sensor digital output (GPIO 27) - Left side, SAFE PIN

// Door sensor type: true = digital touch switch, false = capacitive touch
#define DOOR_SENSOR_DIGITAL true   // Set to true for touch switch modules, false for capacitive

// Sensor data structures
struct DoorData {
  int rawValue;      // Raw reading
  bool doorOpen;     // True if door is open (touch switch activated)
  bool valid;
};

struct VibrationData {
  bool detected;     // True if vibration detected
  int level;         // Vibration level (0-100)
  bool alert;        // True if break-in attempt detected
  bool valid;
};

// Interrupt handler for vibration sensor (must be in global scope)
void IRAM_ATTR vibrationInterruptHandler();

class SensorManager {
public:
  static void initialize();
  static DoorData readDoor();
  static VibrationData readVibration();
  
  // Interrupt-related (accessible by ISR)
  static volatile bool vibrationTriggered;
  static volatile unsigned long lastInterruptTime;
  
private:
  static bool doorInitialized;
  static bool vibrationInitialized;
  static unsigned long lastVibrationTime;
  static int vibrationCount;
  
  // Door sensor reading
  static int readDoorRaw();
};

#endif
