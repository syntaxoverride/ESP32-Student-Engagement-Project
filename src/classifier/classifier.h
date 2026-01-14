#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <Arduino.h>

// Strictness levels
#define STRICTNESS_STRICT 0
#define STRICTNESS_NORMAL 1
#define STRICTNESS_LENIENT 2

// Thresholds for each strictness level
#define THRESHOLD_STRICT 30
#define THRESHOLD_NORMAL 40
#define THRESHOLD_LENIENT 55

// Maximum number of reasons to return
#define MAX_REASONS 10

struct PhishingResult {
  const char* verdict;  // "Safe" or "Suspicious"
  int score;            // 0-100
  int threshold;        // Current threshold used
  const char* reasons[MAX_REASONS];
  int reasonCount;
  int reasonFlags;      // Bitmask of detected reasons (for statistics)
};

class Classifier {
public:
  static PhishingResult analyze(const String& message, int strictnessLevel);
  
private:
  static int calculateScore(const String& message);
  static void extractReasons(const String& message, int score, PhishingResult& result);
  static bool containsKeyword(const String& text, const char* keywords[], int count);
  static bool containsKeywordFromArray(const String& text, const String keywords[], int count);
  static String toLowerCase(const String& str);
};

#endif
