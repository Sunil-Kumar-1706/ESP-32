#include <WiFi.h> // Include Wifi Library
#include "DHT.h" // For Reading DHT11 temperature/humidity sensor
#include "HTTPClient.h" // Sends HTTP requests to web servers(Thingspeak) 

#define DHTPIN 4         // DHT11 data pin connected to GPIO 4
#define DHTTYPE DHT11    // Define DHT sensor type
DHT dht(DHTPIN, DHTTYPE);  // Create DHT object

// WiFi credentials
const char* ssid = "ESP";
const char* password = "*******";

// ThingSpeak settings
String apiKey = "R5VANS83S3TKA8R"; 
const char* server = "http://api.thingspeak.com/update";

void setup() {
  Serial.begin(115200); // Initialize Serial Communication
  dht.begin();  // Initialize DHT sensor

  WiFi.begin(ssid, password);  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

void loop() {
  float temp = dht.readTemperature();   // Read temperature
  float humid = dht.readHumidity();      // Read humidity

  // Check for failed readings
  if (isnan(humid) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Print sensor data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C, Humidity: ");
  Serial.print(humid);
  Serial.println("%");

  // If WiFi is connected, send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Construct the ThingSpeak URL with API key and data
    String url = server;
    url += "?api_key=" + apiKey;
    url += "&field1=" + String(temp);
    url += "&field2=" + String(humid);

    http.begin(url);            // Prepare HTTP request
    int httpCode = http.GET();  // Send GET request

    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak.");
    } 
    else {
      Serial.print("Error sending data. Code: ");
      Serial.println(httpCode);
    }

    http.end();  // End HTTP connection
  }

  delay(15000);  // Wait 15 seconds (ThingSpeak minimum interval)
}