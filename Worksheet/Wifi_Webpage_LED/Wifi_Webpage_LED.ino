#include <WiFi.h>  // Include WiFi Library

const char* ssid = "ESP";
const char* password = "********";

#define LED_PIN 2  // Define LED pin on GPIO 2

WiFiServer server(80);  // Create a web server on port 80

void setup() {
  Serial.begin(115200);          // Start Serial Monitor
  pinMode(LED_PIN, OUTPUT);      // Set LED pin as output
  digitalWrite(LED_PIN, LOW);    // Start with LED OFF

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");           // Print dots while connecting
  }

  // Print IP address once connected
  Serial.println("\nWiFi connected.");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();  // Start the web server
}

void loop() {
  WiFiClient client = server.available();  // Wait for a client to connect

  if (client) {
    Serial.println("New Client Connected");
    String request = "";  // To store client request

    // Read request from client
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;      // Add character to request string
        if (c == '\n') {
          break;           // End of HTTP request
        }
      }
    }

    // Check if user clicked ON or OFF
    if (request.indexOf("GET /on") != -1) {
      digitalWrite(LED_PIN, HIGH);  // Turn ON LED
      Serial.println("LED turned ON");
    }
    else if (request.indexOf("GET /off") != -1) {
      digitalWrite(LED_PIN, LOW);   // Turn OFF LED
      Serial.println("LED turned OFF");
    }

    // Send web page as response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();  // End of headers

    // HTML page content
    client.println("<!DOCTYPE html><html>");
    client.println("<head><title>ESP32 LED Control</title></head>");
    client.println("<body><h2>ESP32 LED Web Control</h2>");
    client.println("<p><a href=\"/on\"><button>Turn LED ON</button></a></p>");
    client.println("<p><a href=\"/off\"><button>Turn LED OFF</button></a></p>");
    client.println("</body></html>");

    delay(1);        // Wait a bit before closing connection
    client.stop();   // Disconnect client
    Serial.println("Client Disconnected");
  }
}