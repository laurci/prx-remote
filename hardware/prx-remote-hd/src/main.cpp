#include <Arduino.h>

#include <Wifi.h>
#include <HTTPClient.h>

#include "config.h"

HTTPClient http;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Starting...");

  WiFi.begin(WIFI_NAME, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.dnsIP());
}

void sendRequest() {
  http.begin(GET_ENDPOINT);
  int httpCode = http.GET();
  http.end();

  Serial.println("Request sent!");
  Serial.print("HTTP code: ");
  Serial.println(httpCode);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(500);
    while(digitalRead(BUTTON_PIN) == LOW) {
      delay(100);
    }

    Serial.println("Button pressed!");
    sendRequest();
  }
}