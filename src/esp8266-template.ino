/*
  template for esp8266 sketch
*/
#include <ESP8266WiFi.h>
#include <RemoteDebug.h>
#include <ArduinoOTA.h>
#include <WiFiManager.h>

#include <ESP8266mDNS.h>       // RemoteDebug dependency
#include <WiFiUdp.h>           // ArduinoOTA dependency
#include <DNSServer.h>         // WiFiManager dependency
#include <ESP8266WebServer.h>  // WiFiManager dependency

#define HOST_NAME "esp8266-template"

// --- LIBRARIES INIT ---
WiFiManager   wifiManager;
RemoteDebug   debug;

// --- SETUP ---
void setup() {

  // create a hotspot to get wifi credentials
  wifiManager.autoConnect(HOST_NAME);

  // remote debug
  Serial.begin(9600);
  debug.begin(HOST_NAME);
  debug.setResetCmdEnabled(true);
  debug.setSerialEnabled(true);

  // over the air update
  ArduinoOTA.setHostname(HOST_NAME);
  ArduinoOTA.begin();
}

// --- MAIN LOOP ---
void loop() {

  // check for updates and remote debug
  ArduinoOTA.handle();
  debug.handle();

  // wait 1s
  delay(1000);
}
