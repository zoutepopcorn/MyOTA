#include "Arduino.h"
#include "MyOTA.h"
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
#include "ESP8266httpUpdate.h"
#define SER Serial
double v = 0.1;

MyOTA::MyOTA() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  //SER.begin(115200);
  SER.println("Ota checker");
  for(uint8_t t = 3; t > 0; t--) {
      SER.printf("v --> %d...\n", t);
      SER.println(v);
      SER.flush();
      delay(1000);
  }
}

void MyOTA::dash() {
  delay(1000);
  delay(250);
}

void MyOTA::checkOTA() {
  SER.println("checkOta()");
  int n = WiFi.scanNetworks();
  SER.println("checkOta()");
  for (int i = 0; i < n; ++i) {
    String nm = WiFi.SSID(i);
    if(nm.substring(0, 2) == "up") {
          SER.println("update");
          String update = "http://" + nm.substring(2) + ".bin";
          SER.println(update);
          t_httpUpdate_return ret = ESPhttpUpdate.update(update);
          switch(ret) {
              case HTTP_UPDATE_FAILED:
                  SER.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
                  break;
              case HTTP_UPDATE_NO_UPDATES:
                  SER.println("HTTP_UPDATE_NO_UPDATES");
                  break;
              case HTTP_UPDATE_OK:
                  SER.println("HTTP_UPDATE_OK");
                  ESP.reset();
                  break;
          }
    } else {
          SER.println(nm);
    }
    delay(10);
  }
}
