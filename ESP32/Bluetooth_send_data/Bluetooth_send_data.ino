#include "BluetoothSerial.h"  // Include Library for Bluetooth communication
#include "DHT.h"              // Include Library for DHT sensor

#define DHTPIN 4              // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11         // type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);     // Create a DHT object with specified pin and type
BluetoothSerial SerialBT;     // Create a BluetoothSerial object

void setup() {
  Serial.begin(115200);               // Start serial communication with the computer
  dht.begin();                        // Initialize DHT sensor
  SerialBT.begin("ESP32_Sensor");     // Start Bluetooth with device name "ESP32_Sensor"
  Serial.println("Bluetooth ready"); 
}

void loop() {
  float temp = dht.readTemperature(); // Read temperature from DHT sensor
  float humid  = dht.readHumidity();    // Read humidity from DHT sensor

  // Check if reading failed (returns NaN), skip this cycle if so
  if (isnan(temp) || isnan(humid)) {
    delay(2000);                      // Wait before retrying
    return;
  }

  // Combine temperature and humidity data into a formatted string
  String data = "Temp: " + String(temp) + " °C, Humidity: " + String(humid) + " %";

  SerialBT.println(data);             // Send data over Bluetooth to the paired device
  Serial.println("Data Sent: " + data);  // Print data on Serial Monitor

  delay(5000);                        // Wait 5 seconds before next reading
}