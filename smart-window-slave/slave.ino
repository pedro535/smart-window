#include <ESP8266WebServer.h>

#define WIFI_SSID "PT-WIFI"
#define WIFI_PASSWORD "rodrigues"

ESP8266WebServer server(80);

void abrir() {
  Serial.println("Get recebido do master");
}

void novoCliente() {
  Serial.println("Novo cliente");
}


void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  server.on("/", HTTP_GET, novoCliente);
  server.on("/abrir", HTTP_GET, abrir); 

  Serial.println(WiFi.localIP());
  server.begin(); 
}

void loop() {
  server.handleClient();
}
