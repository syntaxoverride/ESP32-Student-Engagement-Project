#include "stats.h"

Statistics Stats::stats = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void Stats::initialize() {
  reset();
}

void Stats::recordAnalysis(bool isSuspicious, int reasonFlags) {
  stats.totalAnalyzed++;
  
  if (isSuspicious) {
    stats.suspiciousCount++;
  } else {
    stats.safeCount++;
  }
  
  if (reasonFlags & REASON_URGENCY) stats.urgencyCount++;
  if (reasonFlags & REASON_CREDENTIAL) stats.credentialCount++;
  if (reasonFlags & REASON_REWARD) stats.rewardCount++;
  if (reasonFlags & REASON_IMPERSONATION) stats.impersonationCount++;
  if (reasonFlags & REASON_FINANCIAL) stats.financialCount++;
  if (reasonFlags & REASON_LINK) stats.linkCount++;
}

void Stats::recordChallenge(bool success) {
  stats.challengeAttempts++;
  if (success) {
    stats.challengeSuccesses++;
  }
}

Statistics Stats::getStats() {
  return stats;
}

void Stats::reset() {
  stats.totalAnalyzed = 0;
  stats.safeCount = 0;
  stats.suspiciousCount = 0;
  stats.urgencyCount = 0;
  stats.credentialCount = 0;
  stats.rewardCount = 0;
  stats.impersonationCount = 0;
  stats.financialCount = 0;
  stats.linkCount = 0;
  stats.challengeAttempts = 0;
  stats.challengeSuccesses = 0;
}
