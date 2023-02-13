#include <ESP8266WiFi.h>
#include "aWOT.h"
#include "StaticFiles.h"
#define LED_BUILTIN 2

#define WIFI_SSID "PT-WIFI"
#define WIFI_PASSWORD "rodrigues"

WiFiServer server(80);
Application app;

void abrir(Request &req, Response &res) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  app.get("/abrir", &abrir);

  app.use(staticFiles());

  server.begin();

}

void loop() {
  WiFiClient client = server.available();

  if (client.connected()) {
    app.process(&client);
  }
}
