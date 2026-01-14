#ifndef CAPTIVE_PORTAL_H
#define CAPTIVE_PORTAL_H

#include <WebServer.h>

class CaptivePortal {
public:
  void setup(WebServer* server);
  bool isCaptivePortalRequest(WebServer* server);
  
private:
  void handleCaptivePortal(WebServer* server);
};

#endif
