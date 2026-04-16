#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <ESPmDNS.h>
#include "web/index_html.h"
#include "web/splash_html.h"
#include "web/security_html.h"
#include "web/security_dashboard_html.h"
#include "classifier/classifier.h"
#include "stats/stats.h"
#include "config/config.h"
#include "sensors/sensors.h"

// Station number from build flag (default to 1 if not defined)
#ifndef STATION_NUMBER
#define STATION_NUMBER 1
#endif

// Network configuration - SSID includes station number
char AP_SSID[32];  // Dynamic SSID: "VaultGuard-AI 1", "VaultGuard-AI 2", etc.
const IPAddress AP_IP(192, 168, 4, 1);
const IPAddress AP_GATEWAY(192, 168, 4, 1);
const IPAddress AP_SUBNET(255, 255, 255, 0);

// Portal title - includes station number
String getPortalTitle() {
  return "VaultGuard AI Portal #" + String(STATION_NUMBER);
}

// Server objects
WebServer server(80);
DNSServer dnsServer;

// Classifier strictness level (0=strict, 1=normal, 2=lenient)
int strictnessLevel = 1; // Default: normal

// Helper function to replace placeholders in HTML strings
String replaceHTMLPlaceholder(const String& html, const String& placeholder, const String& replacement) {
  String result = html;
  result.replace(placeholder, replacement);
  return result;
}

// Forward declarations
void handleRoot();
void handleSplash();
void handleVaultGuard();
void handleSecurity();
void handleSecurityDashboard();
void handleSecurityAPI();
void handleAnalyze();
void handleStrictness();
void handleNotFound();
void handleStats();
void handleChallenge();
void handleQuiz();
void handleConfigGet();
void handleConfigKeywords();
void handleConfigSamples();
void handleConfigScoring();
void handleConfigTheme();
void handleConfigQuiz();
void handleConfigReset();
void handleFacilitatorReset();
void handleFacilitatorPanel();

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== VaultGuard AI ===");
  Serial.print("Station Number: ");
  Serial.println(STATION_NUMBER);
  
  // Build SSID with station number
  snprintf(AP_SSID, sizeof(AP_SSID), "VaultGuard-AI %d", STATION_NUMBER);
  
  // Initialize configuration
  ConfigManager::initialize();
  
  // Initialize statistics
  Stats::initialize();
  
  // Initialize sensors
  SensorManager::initialize();
  
  // Configure WiFi AP
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(AP_IP, AP_GATEWAY, AP_SUBNET);
  WiFi.softAP(AP_SSID);
  
  Serial.print("AP SSID: ");
  Serial.println(AP_SSID);
  Serial.print("AP IP: ");
  Serial.println(AP_IP);
  
  // Setup DNS server (resolves all domains to AP IP)
  dnsServer.start(53, "*", AP_IP);
  
  // Setup mDNS for friendly domain name
  if (MDNS.begin("vaultguard")) {
    Serial.println("mDNS responder started");
    Serial.println("Access via: http://vaultguard.local");
    MDNS.addService("http", "tcp", 80);
  } else {
    Serial.println("mDNS failed to start");
  }
  
  // Setup web server routes
  server.on("/", handleSplash);  // Splash page with menu
  server.on("/vaultguard", handleVaultGuard);  // VaultGuard AI (phishing detector)
  server.on("/security", handleSecurity);  // Security Center menu
  server.on("/security/door", handleSecurityDashboard);  // Door sensor dashboard
  server.on("/security/touch", handleSecurityDashboard);  // Door sensor dashboard (alias)
  server.on("/security/vibration", handleSecurityDashboard);  // Vibration sensor dashboard
  server.on("/security/api/door", HTTP_GET, handleSecurityAPI);  // Door sensor API
  server.on("/security/api/touch", HTTP_GET, handleSecurityAPI);  // Door sensor API (alias)
  server.on("/security/api/vibration", HTTP_GET, handleSecurityAPI);  // Vibration sensor API
  server.on("/analyze", HTTP_POST, handleAnalyze);
  server.on("/strictness", HTTP_POST, handleStrictness);
  server.on("/stats", HTTP_GET, handleStats);
  server.on("/challenge", HTTP_POST, handleChallenge);
  server.on("/quiz", HTTP_GET, handleQuiz);
  
  // Builder API endpoints
  server.on("/config", HTTP_GET, handleConfigGet);
  server.on("/config/keywords", HTTP_POST, handleConfigKeywords);
  server.on("/config/samples", HTTP_POST, handleConfigSamples);
  server.on("/config/scoring", HTTP_POST, handleConfigScoring);
  server.on("/config/theme", HTTP_POST, handleConfigTheme);
  server.on("/config/quiz", HTTP_POST, handleConfigQuiz);
  server.on("/config/reset", HTTP_POST, handleConfigReset);
  
  // Facilitator endpoints (hidden URL)
  server.on("/reset", HTTP_GET, handleFacilitatorPanel);
  server.on("/reset", HTTP_POST, handleFacilitatorReset);
  
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP server started");
  Serial.println("Ready for connections!");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  delay(2);
}

void handleSplash() {
  String html = String(SPLASH_HTML);
  String title = getPortalTitle();
  // Replace title in both <title> tag and <h1> heading
  html.replace("VAULTGUARD AI PORTAL", title);
  server.send(200, "text/html", html);
}

void handleVaultGuard() {
  server.send(200, "text/html", INDEX_HTML);
}

void handleSecurity() {
  server.send(200, "text/html", SECURITY_HTML);
}

void handleSecurityDashboard() {
  server.send(200, "text/html", SECURITY_DASHBOARD_HTML);
}

void handleSecurityAPI() {
  String path = server.uri();
  
  if (path.indexOf("/door") >= 0 || path.indexOf("/touch") >= 0) {
    DoorData data = SensorManager::readDoor();
    if (data.valid) {
      String json = "{";
      json += "\"rawValue\":" + String(data.rawValue) + ",";
      json += "\"doorOpen\":" + String(data.doorOpen ? "true" : "false");
      json += "}";
      server.send(200, "application/json", json);
    } else {
      server.send(500, "application/json", "{\"error\":\"Door sensor not available or not connected\"}");
    }
  } else if (path.indexOf("/vibration") >= 0) {
    VibrationData data = SensorManager::readVibration();
    if (data.valid) {
      String json = "{";
      json += "\"detected\":" + String(data.detected ? "true" : "false") + ",";
      json += "\"level\":" + String(data.level) + ",";
      json += "\"alert\":" + String(data.alert ? "true" : "false");
      json += "}";
      server.send(200, "application/json", json);
    } else {
      server.send(500, "application/json", "{\"error\":\"Vibration sensor not available or not connected\"}");
    }
  } else {
    server.send(404, "application/json", "{\"error\":\"Unknown sensor type\"}");
  }
}

void handleAnalyze() {
  String message = "";
  
  // Read message from POST body (form data)
  if (server.hasArg("message")) {
    message = server.arg("message");
  } else if (server.hasArg("plain")) {
    // Fallback for plain text
    message = server.arg("plain");
  } else {
    // Try reading from first argument (some clients send it there)
    message = server.arg(0);
  }
  
  // URL decode the message (form data is URL encoded)
  message.replace("+", " ");
  // Simple URL decode for common characters
  message.replace("%20", " ");
  message.replace("%0A", "\n");
  message.replace("%0D", "\r");
  
  // Trim whitespace
  message.trim();
  
  if (message.length() == 0) {
    server.send(400, "application/json", "{\"error\":\"Missing message\"}");
    return;
  }
  
  // Analyze the message
  PhishingResult result = Classifier::analyze(message, strictnessLevel);
  
  // Record statistics
  bool isSuspicious = (strcmp(result.verdict, "Suspicious") == 0);
  Stats::recordAnalysis(isSuspicious, result.reasonFlags);
  
  // Build JSON response
  String json = "{";
  json += "\"verdict\":\"" + String(result.verdict) + "\",";
  json += "\"score\":" + String(result.score) + ",";
  json += "\"threshold\":" + String(result.threshold) + ",";
  json += "\"reasons\":[";
  for (int i = 0; i < result.reasonCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + String(result.reasons[i]) + "\"";
  }
  json += "]";
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleStrictness() {
  if (server.hasArg("level")) {
    int level = server.arg("level").toInt();
    if (level >= 0 && level <= 2) {
      strictnessLevel = level;
      server.send(200, "application/json", "{\"status\":\"ok\",\"level\":" + String(level) + "}");
    } else {
      server.send(400, "text/plain", "Invalid level (0-2)");
    }
  } else {
    server.send(400, "text/plain", "Missing level parameter");
  }
}

void handleStats() {
  Statistics stats = Stats::getStats();
  
  String json = "{";
  json += "\"totalAnalyzed\":" + String(stats.totalAnalyzed) + ",";
  json += "\"safeCount\":" + String(stats.safeCount) + ",";
  json += "\"suspiciousCount\":" + String(stats.suspiciousCount) + ",";
  json += "\"urgencyCount\":" + String(stats.urgencyCount) + ",";
  json += "\"credentialCount\":" + String(stats.credentialCount) + ",";
  json += "\"rewardCount\":" + String(stats.rewardCount) + ",";
  json += "\"impersonationCount\":" + String(stats.impersonationCount) + ",";
  json += "\"financialCount\":" + String(stats.financialCount) + ",";
  json += "\"linkCount\":" + String(stats.linkCount) + ",";
  json += "\"challengeAttempts\":" + String(stats.challengeAttempts) + ",";
  json += "\"challengeSuccesses\":" + String(stats.challengeSuccesses);
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleChallenge() {
  String message = "";
  
  if (server.hasArg("message")) {
    message = server.arg("message");
  } else {
    message = server.arg(0);
  }
  
  // URL decode
  message.replace("+", " ");
  message.replace("%20", " ");
  message.replace("%0A", "\n");
  message.replace("%0D", "\r");
  message.trim();
  
  if (message.length() == 0) {
    server.send(400, "application/json", "{\"error\":\"Missing message\"}");
    return;
  }
  
  // Analyze with lenient setting (harder to fool)
  PhishingResult result = Classifier::analyze(message, STRICTNESS_LENIENT);
  
  // Challenge: Success if message is suspicious but classified as Safe
  // OR if message is safe but classified as Suspicious (false positive)
  bool challengeSuccess = false;
  String challengeType = "";
  
  // Check if it's actually suspicious (has multiple red flags)
  int actualRedFlags = 0;
  if (result.reasonFlags & REASON_URGENCY) actualRedFlags++;
  if (result.reasonFlags & REASON_CREDENTIAL) actualRedFlags++;
  if (result.reasonFlags & REASON_REWARD) actualRedFlags++;
  if (result.reasonFlags & REASON_IMPERSONATION) actualRedFlags++;
  if (result.reasonFlags & REASON_FINANCIAL) actualRedFlags++;
  if (result.reasonFlags & REASON_LINK) actualRedFlags++;
  
  bool actuallySuspicious = (actualRedFlags >= 2 || result.score >= 50);
  
  if (strcmp(result.verdict, "Safe") == 0 && actuallySuspicious) {
    challengeSuccess = true;
    challengeType = "fooled";
  } else if (strcmp(result.verdict, "Suspicious") == 0 && !actuallySuspicious) {
    challengeSuccess = true;
    challengeType = "false_positive";
  }
  
  Stats::recordChallenge(challengeSuccess);
  
  String json = "{";
  json += "\"verdict\":\"" + String(result.verdict) + "\",";
  json += "\"score\":" + String(result.score) + ",";
  json += "\"challengeSuccess\":" + String(challengeSuccess ? "true" : "false") + ",";
  json += "\"challengeType\":\"" + challengeType + "\",";
  json += "\"reasons\":[";
  for (int i = 0; i < result.reasonCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + String(result.reasons[i]) + "\"";
  }
  json += "]";
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleQuiz() {
  // Return quiz questions from config
  Config config = ConfigManager::getConfig();
  
  String json = "{";
  json += "\"questions\":[";
  for (int i = 0; i < config.quizCount; i++) {
    if (i > 0) json += ",";
    json += config.quizQuestions[i];
  }
  json += "]";
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleConfigGet() {
  Config config = ConfigManager::getConfig();
  
  String json = "{";
  json += "\"keywords\":{";
  json += "\"urgency\":[";
  for (int i = 0; i < config.urgencyCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.urgencyKeywords[i] + "\"";
  }
  json += "],\"credential\":[";
  for (int i = 0; i < config.credentialCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.credentialKeywords[i] + "\"";
  }
  json += "],\"reward\":[";
  for (int i = 0; i < config.rewardCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.rewardKeywords[i] + "\"";
  }
  json += "],\"impersonation\":[";
  for (int i = 0; i < config.impersonationCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.impersonationKeywords[i] + "\"";
  }
  json += "],\"financial\":[";
  for (int i = 0; i < config.financialCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.financialKeywords[i] + "\"";
  }
  json += "]},";
  json += "\"samples\":[";
  for (int i = 0; i < config.sampleCount; i++) {
    if (i > 0) json += ",";
    json += "\"" + config.sampleMessages[i] + "\"";
  }
  json += "],";
  json += "\"scoring\":{";
  json += "\"urgency\":" + String(config.urgencyWeight) + ",";
  json += "\"credential\":" + String(config.credentialWeight) + ",";
  json += "\"reward\":" + String(config.rewardWeight) + ",";
  json += "\"impersonation\":" + String(config.impersonationWeight) + ",";
  json += "\"financial\":" + String(config.financialWeight) + ",";
  json += "\"link\":" + String(config.linkWeight) + ",";
  json += "\"bonus\":" + String(config.multiSignalBonus);
  json += "},";
  json += "\"theme\":{";
  json += "\"primary\":\"" + config.primaryColor + "\",";
  json += "\"secondary\":\"" + config.secondaryColor + "\",";
  json += "\"accent\":\"" + config.accentColor + "\",";
  json += "\"background\":\"" + config.backgroundColor + "\",";
  json += "\"text\":\"" + config.textColor + "\"";
  json += "},";
  json += "\"quiz\":[";
  for (int i = 0; i < config.quizCount; i++) {
    if (i > 0) json += ",";
    json += config.quizQuestions[i];
  }
  json += "]";
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleConfigKeywords() {
  if (!server.hasArg("category") || !server.hasArg("keywords")) {
    server.send(400, "application/json", "{\"error\":\"Missing category or keywords\"}");
    return;
  }
  
  int category = server.arg("category").toInt();
  String keywordsStr = server.arg("keywords");
  
  // Parse comma-separated keywords
  String keywords[30];
  int count = 0;
  int start = 0;
  for (int i = 0; i < keywordsStr.length() && count < 30; i++) {
    if (keywordsStr.charAt(i) == ',' || i == keywordsStr.length() - 1) {
      if (i == keywordsStr.length() - 1) i++;
      keywords[count] = keywordsStr.substring(start, i);
      keywords[count].trim();
      if (keywords[count].length() > 0) count++;
      start = i + 1;
    }
  }
  
  ConfigManager::setKeywords(category, keywords, count);
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleConfigSamples() {
  if (!server.hasArg("samples")) {
    server.send(400, "application/json", "{\"error\":\"Missing samples\"}");
    return;
  }
  
  String samplesStr = server.arg("samples");
  
  // Parse samples (separated by |||)
  String samples[20];
  int count = 0;
  int start = 0;
  for (int i = 0; i < samplesStr.length() && count < 20; i++) {
    if (i + 2 < samplesStr.length() && samplesStr.substring(i, i+3) == "|||") {
      samples[count] = samplesStr.substring(start, i);
      samples[count].trim();
      if (samples[count].length() > 0) count++;
      start = i + 3;
      i += 2;
    } else if (i == samplesStr.length() - 1) {
      samples[count] = samplesStr.substring(start);
      samples[count].trim();
      if (samples[count].length() > 0) count++;
    }
  }
  
  ConfigManager::setSamples(samples, count);
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleConfigScoring() {
  if (!server.hasArg("urgency") || !server.hasArg("credential") || !server.hasArg("reward") || 
      !server.hasArg("impersonation") || !server.hasArg("financial") || !server.hasArg("link") || 
      !server.hasArg("bonus")) {
    server.send(400, "application/json", "{\"error\":\"Missing scoring parameters\"}");
    return;
  }
  
  int urgency = server.arg("urgency").toInt();
  int credential = server.arg("credential").toInt();
  int reward = server.arg("reward").toInt();
  int impersonation = server.arg("impersonation").toInt();
  int financial = server.arg("financial").toInt();
  int link = server.arg("link").toInt();
  int bonus = server.arg("bonus").toInt();
  
  ConfigManager::setScoring(urgency, credential, reward, impersonation, financial, link, bonus);
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleConfigTheme() {
  if (!server.hasArg("primary") || !server.hasArg("secondary") || !server.hasArg("accent") || 
      !server.hasArg("background") || !server.hasArg("text")) {
    server.send(400, "application/json", "{\"error\":\"Missing theme parameters\"}");
    return;
  }
  
  String primary = server.arg("primary");
  String secondary = server.arg("secondary");
  String accent = server.arg("accent");
  String background = server.arg("background");
  String text = server.arg("text");
  
  ConfigManager::setTheme(primary, secondary, accent, background, text);
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleConfigQuiz() {
  if (!server.hasArg("questions")) {
    server.send(400, "application/json", "{\"error\":\"Missing questions\"}");
    return;
  }
  
  String questionsStr = server.arg("questions");
  
  // Parse questions (separated by |||)
  String questions[20];
  int count = 0;
  int start = 0;
  for (int i = 0; i < questionsStr.length() && count < 20; i++) {
    if (i + 2 < questionsStr.length() && questionsStr.substring(i, i+3) == "|||") {
      questions[count] = questionsStr.substring(start, i);
      questions[count].trim();
      if (questions[count].length() > 0) count++;
      start = i + 3;
      i += 2;
    } else if (i == questionsStr.length() - 1) {
      questions[count] = questionsStr.substring(start);
      questions[count].trim();
      if (questions[count].length() > 0) count++;
    }
  }
  
  ConfigManager::setQuizQuestions(questions, count);
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleConfigReset() {
  ConfigManager::resetToDefaults();
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

void handleFacilitatorPanel() {
  // Return facilitator panel HTML (simple password form)
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Facilitator Reset</title>";
  html += "<style>body{font-family:'Courier New',monospace;background:#0a0a0a;color:#00ffff;padding:20px;text-align:center;background-image:linear-gradient(0deg,transparent 24%,rgba(0,255,255,0.05) 25%,rgba(0,255,255,0.05) 26%,transparent 27%,transparent 74%,rgba(0,255,255,0.05) 75%,rgba(0,255,255,0.05) 76%,transparent 77%,transparent),linear-gradient(90deg,transparent 24%,rgba(0,255,255,0.05) 25%,rgba(0,255,255,0.05) 26%,transparent 27%,transparent 74%,rgba(0,255,255,0.05) 75%,rgba(0,255,255,0.05) 76%,transparent 77%,transparent);background-size:50px 50px;}";
  html += ".container{max-width:400px;margin:50px auto;background:rgba(10,10,20,0.95);border:2px solid #00ffff;box-shadow:0 0 20px rgba(0,255,255,0.5);padding:30px;}";
  html += "h1{font-size:24px;text-transform:uppercase;letter-spacing:3px;text-shadow:0 0 10px #00ffff;margin-bottom:20px;}";
  html += "input{padding:12px;margin:15px 0;width:100%;background:rgba(0,0,0,0.8);border:2px solid #00ffff;color:#00ffff;font-family:inherit;box-sizing:border-box;}";
  html += "input:focus{outline:none;border-color:#ff00ff;box-shadow:0 0 15px rgba(255,0,255,0.5);}";
  html += "button{padding:12px 30px;background:linear-gradient(135deg,#00ffff 0%,#0080ff 100%);color:#000;border:2px solid #00ffff;cursor:pointer;font-weight:bold;text-transform:uppercase;letter-spacing:2px;box-shadow:0 0 15px rgba(0,255,255,0.6);transition:all 0.3s;}";
  html += "button:hover{box-shadow:0 0 25px rgba(0,255,255,1);transform:translateY(-2px);}</style></head><body>";
  html += "<div class='container'>";
  html += "<h1>FACILITATOR RESET</h1>";
  html += "<p style='color:rgba(255,255,255,0.8);margin-bottom:20px;'>Enter password to reset entire system:</p>";
  html += "<form method='POST' action='/reset'>";
  html += "<input type='password' name='password' placeholder='Password' required autofocus><br>";
  html += "<button type='submit'>RESET SYSTEM</button>";
  html += "</form>";
  html += "<p style='color:rgba(255,255,255,0.5);font-size:12px;margin-top:20px;'>Password: RESET2025</p>";
  html += "</div></body></html>";
  
  server.send(200, "text/html", html);
}

void handleFacilitatorReset() {
  // Check password
  const char* FACILITATOR_PASSWORD = "RESET2025";
  
  if (!server.hasArg("password")) {
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Error</title>";
    html += "<style>body{font-family:monospace;background:#0a0a0a;color:#ff0000;padding:20px;text-align:center;}</style></head><body>";
    html += "<h1>ERROR</h1><p>Password required</p><a href='/reset' style='color:#00ffff;'>Try Again</a></body></html>";
    server.send(401, "text/html", html);
    return;
  }
  
  if (server.arg("password") != String(FACILITATOR_PASSWORD)) {
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Error</title>";
    html += "<style>body{font-family:monospace;background:#0a0a0a;color:#ff0000;padding:20px;text-align:center;}</style></head><body>";
    html += "<h1>ERROR</h1><p>Invalid password</p><a href='/reset' style='color:#00ffff;'>Try Again</a></body></html>";
    server.send(401, "text/html", html);
    return;
  }
  
  // Reset everything
  ConfigManager::resetToDefaults();
  Stats::reset();
  
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Reset Complete</title>";
  html += "<style>body{font-family:'Courier New',monospace;background:#0a0a0a;color:#00ff00;padding:20px;text-align:center;}";
  html += ".container{max-width:400px;margin:50px auto;background:rgba(0,255,0,0.1);border:2px solid #00ff00;box-shadow:0 0 20px rgba(0,255,0,0.5);padding:30px;}";
  html += "h1{font-size:24px;text-transform:uppercase;letter-spacing:3px;text-shadow:0 0 10px #00ff00;}</style></head><body>";
  html += "<div class='container'>";
  html += "<h1>RESET COMPLETE</h1>";
  html += "<p style='color:rgba(255,255,255,0.8);margin:20px 0;'>All configurations, statistics, and customizations have been reset to defaults.</p>";
  html += "<p style='color:rgba(255,255,255,0.6);font-size:14px;'>System is ready for the next group.</p>";
  html += "<a href='/' style='color:#00ffff;text-decoration:none;display:inline-block;margin-top:20px;padding:10px 20px;border:2px solid #00ffff;'>Return to Portal</a>";
  html += "</div></body></html>";
  
  server.send(200, "text/html", html);
}

void handleNotFound() {
  server.send(404, "text/plain", "Not found");
}
