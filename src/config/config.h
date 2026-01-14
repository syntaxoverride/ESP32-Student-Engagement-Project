#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Maximum limits for configuration arrays
#define MAX_KEYWORDS_PER_CATEGORY 30
#define MAX_SAMPLE_MESSAGES 20
#define MAX_QUIZ_QUESTIONS 20
#define MAX_CONFIG_NAME_LENGTH 32

// Configuration structure
struct Config {
  // Keywords by category
  String urgencyKeywords[MAX_KEYWORDS_PER_CATEGORY];
  int urgencyCount;
  
  String credentialKeywords[MAX_KEYWORDS_PER_CATEGORY];
  int credentialCount;
  
  String rewardKeywords[MAX_KEYWORDS_PER_CATEGORY];
  int rewardCount;
  
  String impersonationKeywords[MAX_KEYWORDS_PER_CATEGORY];
  int impersonationCount;
  
  String financialKeywords[MAX_KEYWORDS_PER_CATEGORY];
  int financialCount;
  
  // Sample messages
  String sampleMessages[MAX_SAMPLE_MESSAGES];
  int sampleCount;
  
  // Scoring weights
  int urgencyWeight;
  int credentialWeight;
  int rewardWeight;
  int impersonationWeight;
  int financialWeight;
  int linkWeight;
  int multiSignalBonus;
  
  // Theme colors
  String primaryColor;
  String secondaryColor;
  String accentColor;
  String backgroundColor;
  String textColor;
  
  // Quiz questions (simplified - stored as JSON strings)
  String quizQuestions[MAX_QUIZ_QUESTIONS];
  int quizCount;
  
  // Configuration name
  String configName;
};

class ConfigManager {
public:
  static void initialize();
  static Config getConfig();
  static void setConfig(const Config& config);
  static void resetToDefaults();
  static void loadDefaults();
  
  // Individual setters
  static void setKeywords(int category, const String keywords[], int count);
  static void setSamples(const String samples[], int count);
  static void setScoring(int urgency, int credential, int reward, int impersonation, int financial, int link, int bonus);
  static void setTheme(const String& primary, const String& secondary, const String& accent, const String& bg, const String& text);
  static void setQuizQuestions(const String questions[], int count);
  
  // Getters
  static void getKeywords(int category, String keywords[], int& count);
  static void getSamples(String samples[], int& count);
  static void getScoring(int& urgency, int& credential, int& reward, int& impersonation, int& financial, int& link, int& bonus);
  static void getTheme(String& primary, String& secondary, String& accent, String& bg, String& text);
  static void getQuizQuestions(String questions[], int& count);
  
private:
  static Config currentConfig;
  static void copyConfig(const Config& src, Config& dst);
};

// Category constants
#define CATEGORY_URGENCY 0
#define CATEGORY_CREDENTIAL 1
#define CATEGORY_REWARD 2
#define CATEGORY_IMPERSONATION 3
#define CATEGORY_FINANCIAL 4

#endif
