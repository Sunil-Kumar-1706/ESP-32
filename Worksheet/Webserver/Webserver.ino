#include <WiFi.h>  // Include WiFi library for ESP32

const char* ssid     = "FUN";        // WiFi SSID
const char* password = "*******";    // WiFi password

WiFiServer server(80);  // Create a web server on port 80 (HTTP)

void setup() {
  Serial.begin(115200);      // Start serial communication
  WiFi.begin(ssid, password);  // Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) { // Wait until connected
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());  // Print local IP address

  server.begin();  // Start the server
}

void loop() {
  WiFiClient client = server.available();  // Check if a client has connected

  if (client) {
    String currentRequest = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        currentRequest += c;

        // On receiving a full line (end of HTTP request line)
        if (c == '\n') {
          // Send standard HTTP response
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          // Send simple HTML content
          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head><title>ESP32 Web Server</title></head>");
          client.println("<body><h1>Welcome from ESP32</h1>");
          client.println("<p>This is a simple web page</p>");
          client.println("</body></html>");

          break;  // Exit loop after sending response
        }
      }
    }

    delay(1);     
    client.stop(); // Close the connection
  }
}