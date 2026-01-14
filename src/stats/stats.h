#ifndef STATS_H
#define STATS_H

#include <Arduino.h>

struct Statistics {
  int totalAnalyzed;
  int safeCount;
  int suspiciousCount;
  int urgencyCount;
  int credentialCount;
  int rewardCount;
  int impersonationCount;
  int financialCount;
  int linkCount;
  int challengeAttempts;
  int challengeSuccesses;
};

class Stats {
public:
  static void initialize();
  static void recordAnalysis(bool isSuspicious, int reasonFlags);
  static void recordChallenge(bool success);
  static Statistics getStats();
  static void reset();
  
private:
  static Statistics stats;
};

// Reason flags (bitmask) - must match classifier.cpp
#define REASON_URGENCY 0x01
#define REASON_CREDENTIAL 0x02
#define REASON_REWARD 0x04
#define REASON_IMPERSONATION 0x08
#define REASON_FINANCIAL 0x10
#define REASON_LINK 0x20

#endif
