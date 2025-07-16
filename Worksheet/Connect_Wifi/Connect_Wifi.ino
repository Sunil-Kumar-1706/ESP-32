#include <WiFi.h>  // Include WiFi library for ESP32

const char* ssid = "WIFI";       // WiFi network name (SSID)
const char* password = "********";  // WiFi password

void setup() {
  Serial.begin(115200);  // Start serial communication
  delay(1000);           

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);  // Start connecting to WiFi

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");   
  }

  Serial.println();
  Serial.println("WiFi Connected!");  // Success message
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());     // Print IP address
}

void loop() {
  // WiFi is already connected
}