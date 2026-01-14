#include "classifier.h"
#include "../stats/stats.h"
#include "../config/config.h"

PhishingResult Classifier::analyze(const String& message, int strictnessLevel) {
  PhishingResult result;
  result.reasonCount = 0;
  result.reasonFlags = 0;
  
  // Calculate base score
  result.score = calculateScore(message);
  
  // Determine threshold based on strictness
  switch (strictnessLevel) {
    case STRICTNESS_STRICT:
      result.threshold = THRESHOLD_STRICT;
      break;
    case STRICTNESS_NORMAL:
      result.threshold = THRESHOLD_NORMAL;
      break;
    case STRICTNESS_LENIENT:
      result.threshold = THRESHOLD_LENIENT;
      break;
    default:
      result.threshold = THRESHOLD_NORMAL;
  }
  
  // Determine verdict
  result.verdict = (result.score >= result.threshold) ? "Suspicious" : "Safe";
  
  // Extract reasons (also sets reasonFlags)
  extractReasons(message, result.score, result);
  
  return result;
}

int Classifier::calculateScore(const String& message) {
  String lowerMsg = toLowerCase(message);
  int score = 0;
  
  // Get configuration
  Config config = ConfigManager::getConfig();
  int urgencyWeight, credentialWeight, rewardWeight, impersonationWeight, financialWeight, linkWeight, bonus;
  ConfigManager::getScoring(urgencyWeight, credentialWeight, rewardWeight, impersonationWeight, financialWeight, linkWeight, bonus);
  
  // Get keywords from config
  String urgencyKeywords[30], credentialKeywords[30], rewardKeywords[30], impersonationKeywords[30], financialKeywords[30];
  int urgencyCount, credentialCount, rewardCount, impersonationCount, financialCount;
  
  ConfigManager::getKeywords(CATEGORY_URGENCY, urgencyKeywords, urgencyCount);
  ConfigManager::getKeywords(CATEGORY_CREDENTIAL, credentialKeywords, credentialCount);
  ConfigManager::getKeywords(CATEGORY_REWARD, rewardKeywords, rewardCount);
  ConfigManager::getKeywords(CATEGORY_IMPERSONATION, impersonationKeywords, impersonationCount);
  ConfigManager::getKeywords(CATEGORY_FINANCIAL, financialKeywords, financialCount);
  
  // Check for urgency language
  if (containsKeywordFromArray(lowerMsg, urgencyKeywords, urgencyCount)) {
    score += urgencyWeight;
  }
  
  // Check for credential requests
  if (containsKeywordFromArray(lowerMsg, credentialKeywords, credentialCount)) {
    score += credentialWeight;
  }
  
  // Check for reward bait
  if (containsKeywordFromArray(lowerMsg, rewardKeywords, rewardCount)) {
    score += rewardWeight;
  }
  
  // Check for impersonation
  if (containsKeywordFromArray(lowerMsg, impersonationKeywords, impersonationCount)) {
    score += impersonationWeight;
  }
  
  // Check for financial pressure
  if (containsKeywordFromArray(lowerMsg, financialKeywords, financialCount)) {
    score += financialWeight;
  }
  
  // Check for suspicious links
  // Links are more suspicious when combined with other signals
  bool hasLink = (lowerMsg.indexOf("http://") >= 0 || lowerMsg.indexOf("https://") >= 0 || 
                  lowerMsg.indexOf("www.") >= 0 || lowerMsg.indexOf(".com") >= 0 ||
                  lowerMsg.indexOf("click here") >= 0 || lowerMsg.indexOf("click this") >= 0 ||
                  lowerMsg.indexOf("click") >= 0);
  
  // Count other signals first (before adding link score)
  int otherSignalCount = 0;
  if (containsKeywordFromArray(lowerMsg, urgencyKeywords, urgencyCount)) otherSignalCount++;
  if (containsKeywordFromArray(lowerMsg, credentialKeywords, credentialCount)) otherSignalCount++;
  if (containsKeywordFromArray(lowerMsg, rewardKeywords, rewardCount)) otherSignalCount++;
  if (containsKeywordFromArray(lowerMsg, impersonationKeywords, impersonationCount)) otherSignalCount++;
  if (containsKeywordFromArray(lowerMsg, financialKeywords, financialCount)) otherSignalCount++;
  
  // Links alone are somewhat suspicious, but links + other signals are very suspicious
  if (hasLink) {
    if (otherSignalCount > 0) {
      // Link combined with other signals = more suspicious
      score += linkWeight + (otherSignalCount * 5);
    } else {
      // Link alone - still suspicious, especially if it's a URL
      // URLs are more suspicious than just "click here"
      if (lowerMsg.indexOf("http://") >= 0 || lowerMsg.indexOf("https://") >= 0 || 
          lowerMsg.indexOf("www.") >= 0) {
        // Actual URLs should be suspicious enough to trigger on Strict mode (threshold 30)
        // So we need at least 30 points for a URL alone
        score += linkWeight + 15; // Extra points for actual URLs - ensures it triggers
      } else {
        // Just "click here" without URL - less suspicious but still notable
        score += linkWeight + 5;
      }
    }
  }
  
  // Bonus: Multiple signals increase suspicion
  int signalCount = otherSignalCount;
  if (hasLink) signalCount++;
  
  // Bonus points for multiple signals
  if (signalCount >= 3) {
    score += bonus;
  }
  if (signalCount >= 4) {
    score += (bonus / 2);
  }
  
  // Cap at 100
  if (score > 100) score = 100;
  
  return score;
}

void Classifier::extractReasons(const String& message, int score, PhishingResult& result) {
  String lowerMsg = toLowerCase(message);
  
  // Get keywords from config
  String urgencyKeywords[30], credentialKeywords[30], rewardKeywords[30], impersonationKeywords[30], financialKeywords[30];
  int urgencyCount, credentialCount, rewardCount, impersonationCount, financialCount;
  
  ConfigManager::getKeywords(CATEGORY_URGENCY, urgencyKeywords, urgencyCount);
  ConfigManager::getKeywords(CATEGORY_CREDENTIAL, credentialKeywords, credentialCount);
  ConfigManager::getKeywords(CATEGORY_REWARD, rewardKeywords, rewardCount);
  ConfigManager::getKeywords(CATEGORY_IMPERSONATION, impersonationKeywords, impersonationCount);
  ConfigManager::getKeywords(CATEGORY_FINANCIAL, financialKeywords, financialCount);
  
  if (containsKeywordFromArray(lowerMsg, urgencyKeywords, urgencyCount) && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Urgency language detected";
    result.reasonFlags |= REASON_URGENCY;
  }
  
  if (containsKeywordFromArray(lowerMsg, credentialKeywords, credentialCount) && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Credential request keywords";
    result.reasonFlags |= REASON_CREDENTIAL;
  }
  
  if (containsKeywordFromArray(lowerMsg, rewardKeywords, rewardCount) && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Reward bait detected";
    result.reasonFlags |= REASON_REWARD;
  }
  
  if (containsKeywordFromArray(lowerMsg, impersonationKeywords, impersonationCount) && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Impersonation cues";
    result.reasonFlags |= REASON_IMPERSONATION;
  }
  
  if (containsKeywordFromArray(lowerMsg, financialKeywords, financialCount) && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Financial pressure keywords";
    result.reasonFlags |= REASON_FINANCIAL;
  }
  
  bool hasLink = (lowerMsg.indexOf("http://") >= 0 || lowerMsg.indexOf("https://") >= 0 || 
                  lowerMsg.indexOf("www.") >= 0 || lowerMsg.indexOf("click here") >= 0 ||
                  lowerMsg.indexOf("click") >= 0);
  if (hasLink && result.reasonCount < MAX_REASONS) {
    result.reasons[result.reasonCount++] = "Suspicious link present";
    result.reasonFlags |= REASON_LINK;
  }
}

bool Classifier::containsKeyword(const String& text, const char* keywords[], int count) {
  for (int i = 0; i < count; i++) {
    if (text.indexOf(keywords[i]) >= 0) {
      return true;
    }
  }
  return false;
}

bool Classifier::containsKeywordFromArray(const String& text, const String keywords[], int count) {
  for (int i = 0; i < count; i++) {
    String lowerKeyword = toLowerCase(keywords[i]);
    if (text.indexOf(lowerKeyword) >= 0) {
      return true;
    }
  }
  return false;
}

String Classifier::toLowerCase(const String& str) {
  String result = str;
  result.toLowerCase();
  return result;
}
