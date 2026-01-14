#include "captive_portal.h"
#include <WiFi.h>
#include "../web/captive_portal_html.h"

void CaptivePortal::setup(WebServer* server) {
  // Common captive portal detection endpoints - serve welcome page
  server->on("/generate_204", [server]() {
    server->send(200, "text/html", CAPTIVE_PORTAL_HTML);
  });
  
  server->on("/gen_204", [server]() {
    server->send(200, "text/html", CAPTIVE_PORTAL_HTML);
  });
  
  server->on("/hotspot-detect.html", [server]() {
    server->send(200, "text/html", CAPTIVE_PORTAL_HTML);
  });
  
  server->on("/connecttest.txt", [server]() {
    server->send(200, "text/plain", "Microsoft Connect Test");
  });
  
  server->on("/redirect", [server]() {
    server->send(200, "text/html", CAPTIVE_PORTAL_HTML);
  });
}

bool CaptivePortal::isCaptivePortalRequest(WebServer* server) {
  String host = server->hostHeader();
  
  // If host header is empty or not our IP, likely a captive portal request
  if (host.length() == 0 || host != "192.168.4.1") {
    return true;
  }
  
  return false;
}
