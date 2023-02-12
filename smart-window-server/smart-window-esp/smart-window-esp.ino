#include <ESP8266WiFi.h>
#include "aWOT.h"
#include "StaticFiles.h"
#define LED_BUILTIN 2

#define WIFI_SSID "network"
#define WIFI_PASSWORD "password"

WiFiServer server(80);
Application app;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  app.use(staticFiles());

  server.begin();

  // setup confirmation signal
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }

}

void loop() {
  WiFiClient client = server.available();

  if (client.connected()) {
    app.process(&client);
  }
}