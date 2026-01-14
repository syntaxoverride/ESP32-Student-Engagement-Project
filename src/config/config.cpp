#include "config.h"

Config ConfigManager::currentConfig;

void ConfigManager::initialize() {
  loadDefaults();
}

void ConfigManager::loadDefaults() {
  currentConfig.urgencyCount = 15;
  currentConfig.urgencyKeywords[0] = "urgent";
  currentConfig.urgencyKeywords[1] = "immediately";
  currentConfig.urgencyKeywords[2] = "asap";
  currentConfig.urgencyKeywords[3] = "right now";
  currentConfig.urgencyKeywords[4] = "act now";
  currentConfig.urgencyKeywords[5] = "expires";
  currentConfig.urgencyKeywords[6] = "expiring";
  currentConfig.urgencyKeywords[7] = "limited time";
  currentConfig.urgencyKeywords[8] = "today only";
  currentConfig.urgencyKeywords[9] = "within 24 hours";
  currentConfig.urgencyKeywords[10] = "hurry";
  currentConfig.urgencyKeywords[11] = "deadline";
  currentConfig.urgencyKeywords[12] = "time sensitive";
  currentConfig.urgencyKeywords[13] = "action required";
  currentConfig.urgencyKeywords[14] = "respond now";
  
  currentConfig.credentialCount = 13;
  currentConfig.credentialKeywords[0] = "password";
  currentConfig.credentialKeywords[1] = "verify account";
  currentConfig.credentialKeywords[2] = "confirm identity";
  currentConfig.credentialKeywords[3] = "login";
  currentConfig.credentialKeywords[4] = "credentials";
  currentConfig.credentialKeywords[5] = "username";
  currentConfig.credentialKeywords[6] = "account suspended";
  currentConfig.credentialKeywords[7] = "account locked";
  currentConfig.credentialKeywords[8] = "verify email";
  currentConfig.credentialKeywords[9] = "update account";
  currentConfig.credentialKeywords[10] = "verify information";
  currentConfig.credentialKeywords[11] = "confirm details";
  currentConfig.credentialKeywords[12] = "security check";
  
  currentConfig.rewardCount = 14;
  currentConfig.rewardKeywords[0] = "prize";
  currentConfig.rewardKeywords[1] = "winner";
  currentConfig.rewardKeywords[2] = "congratulations";
  currentConfig.rewardKeywords[3] = "you won";
  currentConfig.rewardKeywords[4] = "claim your";
  currentConfig.rewardKeywords[5] = "free gift";
  currentConfig.rewardKeywords[6] = "claim now";
  currentConfig.rewardKeywords[7] = "reward";
  currentConfig.rewardKeywords[8] = "bonus";
  currentConfig.rewardKeywords[9] = "cash prize";
  currentConfig.rewardKeywords[10] = "you've won";
  currentConfig.rewardKeywords[11] = "you have won";
  currentConfig.rewardKeywords[12] = "claim prize";
  currentConfig.rewardKeywords[13] = "free money";
  
  currentConfig.impersonationCount = 13;
  currentConfig.impersonationKeywords[0] = "irs";
  currentConfig.impersonationKeywords[1] = "microsoft";
  currentConfig.impersonationKeywords[2] = "apple";
  currentConfig.impersonationKeywords[3] = "amazon";
  currentConfig.impersonationKeywords[4] = "paypal";
  currentConfig.impersonationKeywords[5] = "bank";
  currentConfig.impersonationKeywords[6] = "it department";
  currentConfig.impersonationKeywords[7] = "support team";
  currentConfig.impersonationKeywords[8] = "security team";
  currentConfig.impersonationKeywords[9] = "administrator";
  currentConfig.impersonationKeywords[10] = "tech support";
  currentConfig.impersonationKeywords[11] = "customer service";
  currentConfig.impersonationKeywords[12] = "help desk";
  
  currentConfig.financialCount = 14;
  currentConfig.financialKeywords[0] = "payment due";
  currentConfig.financialKeywords[1] = "invoice";
  currentConfig.financialKeywords[2] = "overdue";
  currentConfig.financialKeywords[3] = "pay now";
  currentConfig.financialKeywords[4] = "billing";
  currentConfig.financialKeywords[5] = "charge";
  currentConfig.financialKeywords[6] = "refund";
  currentConfig.financialKeywords[7] = "transaction";
  currentConfig.financialKeywords[8] = "unauthorized charge";
  currentConfig.financialKeywords[9] = "verify payment";
  currentConfig.financialKeywords[10] = "payment failed";
  currentConfig.financialKeywords[11] = "payment required";
  currentConfig.financialKeywords[12] = "billing issue";
  currentConfig.financialKeywords[13] = "account balance";
  
  currentConfig.sampleCount = 6;
  currentConfig.sampleMessages[0] = "Hi, just wanted to check in and see how you're doing. Hope you're having a great day!";
  currentConfig.sampleMessages[1] = "URGENT: Your account will be locked within 24 hours. Click here immediately to verify your identity: http://verify-now.com";
  currentConfig.sampleMessages[2] = "Congratulations! You've won a $1000 cash prize! Claim your reward now by clicking this link: www.claimprize.com";
  currentConfig.sampleMessages[3] = "This is the IT department. We detected suspicious activity on your account. Please verify your login credentials immediately to prevent account suspension.";
  currentConfig.sampleMessages[4] = "Your payment of $299.99 is overdue. Pay now to avoid service interruption. Click here to make payment: pay-now.com";
  currentConfig.sampleMessages[5] = "Your package delivery failed. Click here to reschedule: http://delivery-reschedule.net/verify";
  
  // Default scoring weights
  currentConfig.urgencyWeight = 20;
  currentConfig.credentialWeight = 25;
  currentConfig.rewardWeight = 20;
  currentConfig.impersonationWeight = 25;
  currentConfig.financialWeight = 25;
  currentConfig.linkWeight = 20;  // Increased from 15 - links are more suspicious
  currentConfig.multiSignalBonus = 10;
  
  // Default theme (cyberpunk)
  currentConfig.primaryColor = "#00ffff";
  currentConfig.secondaryColor = "#ff00ff";
  currentConfig.accentColor = "#00ff00";
  currentConfig.backgroundColor = "#0a0a0a";
  currentConfig.textColor = "#00ffff";
  
  // Default quiz questions (stored as JSON strings)
  currentConfig.quizCount = 5;
  currentConfig.quizQuestions[0] = "{\"id\":1,\"question\":\"What is phishing?\",\"options\":[\"A type of fish\",\"A cybersecurity attack using fake emails\",\"A computer virus\",\"A type of encryption\"],\"correct\":1}";
  currentConfig.quizQuestions[1] = "{\"id\":2,\"question\":\"Which is a red flag in an email?\",\"options\":[\"Your name in the greeting\",\"Urgent language asking for immediate action\",\"Professional formatting\",\"A clear sender address\"],\"correct\":1}";
  currentConfig.quizQuestions[2] = "{\"id\":3,\"question\":\"What should you do if you receive a suspicious email?\",\"options\":[\"Click all links immediately\",\"Delete it and report it\",\"Forward it to everyone\",\"Ignore it completely\"],\"correct\":1}";
  currentConfig.quizQuestions[3] = "{\"id\":4,\"question\":\"What is two-factor authentication (2FA)?\",\"options\":[\"Using two passwords\",\"An extra security step beyond password\",\"Having two email accounts\",\"Using two computers\"],\"correct\":1}";
  currentConfig.quizQuestions[4] = "{\"id\":5,\"question\":\"Which URL looks most suspicious?\",\"options\":[\"https://www.bank.com\",\"https://www.bank-secure-verify.net\",\"https://login.bank.com\",\"https://www.bank.com/login\"],\"correct\":1}";
  
  currentConfig.configName = "Default";
}

Config ConfigManager::getConfig() {
  return currentConfig;
}

void ConfigManager::setConfig(const Config& config) {
  copyConfig(config, currentConfig);
}

void ConfigManager::resetToDefaults() {
  loadDefaults();
}

void ConfigManager::setKeywords(int category, const String keywords[], int count) {
  String* targetArray = nullptr;
  int* targetCount = nullptr;
  
  switch(category) {
    case CATEGORY_URGENCY:
      targetArray = currentConfig.urgencyKeywords;
      targetCount = &currentConfig.urgencyCount;
      break;
    case CATEGORY_CREDENTIAL:
      targetArray = currentConfig.credentialKeywords;
      targetCount = &currentConfig.credentialCount;
      break;
    case CATEGORY_REWARD:
      targetArray = currentConfig.rewardKeywords;
      targetCount = &currentConfig.rewardCount;
      break;
    case CATEGORY_IMPERSONATION:
      targetArray = currentConfig.impersonationKeywords;
      targetCount = &currentConfig.impersonationCount;
      break;
    case CATEGORY_FINANCIAL:
      targetArray = currentConfig.financialKeywords;
      targetCount = &currentConfig.financialCount;
      break;
  }
  
  if (targetArray && targetCount) {
    int maxCount = (count > MAX_KEYWORDS_PER_CATEGORY) ? MAX_KEYWORDS_PER_CATEGORY : count;
    *targetCount = maxCount;
    for (int i = 0; i < maxCount; i++) {
      targetArray[i] = keywords[i];
    }
  }
}

void ConfigManager::setSamples(const String samples[], int count) {
  int maxCount = (count > MAX_SAMPLE_MESSAGES) ? MAX_SAMPLE_MESSAGES : count;
  currentConfig.sampleCount = maxCount;
  for (int i = 0; i < maxCount; i++) {
    currentConfig.sampleMessages[i] = samples[i];
  }
}

void ConfigManager::setScoring(int urgency, int credential, int reward, int impersonation, int financial, int link, int bonus) {
  currentConfig.urgencyWeight = urgency;
  currentConfig.credentialWeight = credential;
  currentConfig.rewardWeight = reward;
  currentConfig.impersonationWeight = impersonation;
  currentConfig.financialWeight = financial;
  currentConfig.linkWeight = link;
  currentConfig.multiSignalBonus = bonus;
}

void ConfigManager::setTheme(const String& primary, const String& secondary, const String& accent, const String& bg, const String& text) {
  currentConfig.primaryColor = primary;
  currentConfig.secondaryColor = secondary;
  currentConfig.accentColor = accent;
  currentConfig.backgroundColor = bg;
  currentConfig.textColor = text;
}

void ConfigManager::setQuizQuestions(const String questions[], int count) {
  int maxCount = (count > MAX_QUIZ_QUESTIONS) ? MAX_QUIZ_QUESTIONS : count;
  currentConfig.quizCount = maxCount;
  for (int i = 0; i < maxCount; i++) {
    currentConfig.quizQuestions[i] = questions[i];
  }
}

void ConfigManager::getKeywords(int category, String keywords[], int& count) {
  String* sourceArray = nullptr;
  int* sourceCount = nullptr;
  
  switch(category) {
    case CATEGORY_URGENCY:
      sourceArray = currentConfig.urgencyKeywords;
      sourceCount = &currentConfig.urgencyCount;
      break;
    case CATEGORY_CREDENTIAL:
      sourceArray = currentConfig.credentialKeywords;
      sourceCount = &currentConfig.credentialCount;
      break;
    case CATEGORY_REWARD:
      sourceArray = currentConfig.rewardKeywords;
      sourceCount = &currentConfig.rewardCount;
      break;
    case CATEGORY_IMPERSONATION:
      sourceArray = currentConfig.impersonationKeywords;
      sourceCount = &currentConfig.impersonationCount;
      break;
    case CATEGORY_FINANCIAL:
      sourceArray = currentConfig.financialKeywords;
      sourceCount = &currentConfig.financialCount;
      break;
  }
  
  if (sourceArray && sourceCount) {
    count = *sourceCount;
    for (int i = 0; i < count; i++) {
      keywords[i] = sourceArray[i];
    }
  } else {
    count = 0;
  }
}

void ConfigManager::getSamples(String samples[], int& count) {
  count = currentConfig.sampleCount;
  for (int i = 0; i < count; i++) {
    samples[i] = currentConfig.sampleMessages[i];
  }
}

void ConfigManager::getScoring(int& urgency, int& credential, int& reward, int& impersonation, int& financial, int& link, int& bonus) {
  urgency = currentConfig.urgencyWeight;
  credential = currentConfig.credentialWeight;
  reward = currentConfig.rewardWeight;
  impersonation = currentConfig.impersonationWeight;
  financial = currentConfig.financialWeight;
  link = currentConfig.linkWeight;
  bonus = currentConfig.multiSignalBonus;
}

void ConfigManager::getTheme(String& primary, String& secondary, String& accent, String& bg, String& text) {
  primary = currentConfig.primaryColor;
  secondary = currentConfig.secondaryColor;
  accent = currentConfig.accentColor;
  bg = currentConfig.backgroundColor;
  text = currentConfig.textColor;
}

void ConfigManager::getQuizQuestions(String questions[], int& count) {
  count = currentConfig.quizCount;
  for (int i = 0; i < count; i++) {
    questions[i] = currentConfig.quizQuestions[i];
  }
}

void ConfigManager::copyConfig(const Config& src, Config& dst) {
  // Copy keywords
  for (int i = 0; i < src.urgencyCount; i++) {
    dst.urgencyKeywords[i] = src.urgencyKeywords[i];
  }
  dst.urgencyCount = src.urgencyCount;
  
  for (int i = 0; i < src.credentialCount; i++) {
    dst.credentialKeywords[i] = src.credentialKeywords[i];
  }
  dst.credentialCount = src.credentialCount;
  
  for (int i = 0; i < src.rewardCount; i++) {
    dst.rewardKeywords[i] = src.rewardKeywords[i];
  }
  dst.rewardCount = src.rewardCount;
  
  for (int i = 0; i < src.impersonationCount; i++) {
    dst.impersonationKeywords[i] = src.impersonationKeywords[i];
  }
  dst.impersonationCount = src.impersonationCount;
  
  for (int i = 0; i < src.financialCount; i++) {
    dst.financialKeywords[i] = src.financialKeywords[i];
  }
  dst.financialCount = src.financialCount;
  
  // Copy samples
  for (int i = 0; i < src.sampleCount; i++) {
    dst.sampleMessages[i] = src.sampleMessages[i];
  }
  dst.sampleCount = src.sampleCount;
  
  // Copy scoring
  dst.urgencyWeight = src.urgencyWeight;
  dst.credentialWeight = src.credentialWeight;
  dst.rewardWeight = src.rewardWeight;
  dst.impersonationWeight = src.impersonationWeight;
  dst.financialWeight = src.financialWeight;
  dst.linkWeight = src.linkWeight;
  dst.multiSignalBonus = src.multiSignalBonus;
  
  // Copy theme
  dst.primaryColor = src.primaryColor;
  dst.secondaryColor = src.secondaryColor;
  dst.accentColor = src.accentColor;
  dst.backgroundColor = src.backgroundColor;
  dst.textColor = src.textColor;
  
  // Copy quiz
  for (int i = 0; i < src.quizCount; i++) {
    dst.quizQuestions[i] = src.quizQuestions[i];
  }
  dst.quizCount = src.quizCount;
  
  dst.configName = src.configName;
}
