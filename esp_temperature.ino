#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include "SFE_BMP180.hpp"
#include "functions.hpp"

SFE_BMP180 pressure;

#define ALTITUDE 14.0

double p_init = 0;

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 delay(3000);
 Serial.begin(115200);
 Serial.println();
 Serial.print("Booting...");
 wifi_setup ();
 arduinoOTA_setup();
 if (pressure.begin()) {
    Serial.println("BMP180 init success");
  } else {
    Serial.println("BMP180 init fail\n\n");
  }
}
void loop() {
  ArduinoOTA.handle();
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
}
