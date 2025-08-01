#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid = "ssid";
const char* password = "password";
const char* serverIP = "serverIP";
int serverPort = 80;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("WiFi bağlaniyor...");}
  Serial.println("WiFi bağlandi !!");}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverURL = "http://" + String(serverIP) + ":" + String(serverPort);
    http.begin(serverURL);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.print("Server Cevabi : ");
      Serial.println(payload);
    } else {
      Serial.print("Hatali Kod: ");
      Serial.println(httpResponseCode); }
    http.end(); }
delay(5000); }