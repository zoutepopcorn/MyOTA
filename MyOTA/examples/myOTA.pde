/*
      Build by Johan Hoeksma.
 */
#include <MyOTA.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

double ver = 0.1;
MyOTA ota;
WiFiManager wifiManager;

void reset() {
      wifiManager.resetSettings();
}

void setup() {
      Serial.begin(115200);
      wifiManager.setDebugOutput(true);
      wifiManager.autoConnect("setup", "00000000");
      ota.checkOTA();
      delay(3000);
}

void loop() {
      Serial.print("Version = ");
      Serial.println(ver);
      delay(5000);
}
