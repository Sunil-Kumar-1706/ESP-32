#include "BluetoothSerial.h"  // Include Bluetooth Serial library

BluetoothSerial SerialBT;     // Create an object of BluetoothSerial

void setup() {
  Serial.begin(115200);               // Start serial communication with PC 
  SerialBT.begin("ESP32_bluetooth");  // Start Bluetooth with device name "ESP32_bluetooth"
  Serial.println("Device started, now you can pair it with bluetooth!");
}

void loop() {
  // If data is available from the Serial Monitor (PC to ESP32)
  if (Serial.available()) {
    SerialBT.write(Serial.read());    // Read one byte from Serial and send it over Bluetooth
  }

  // If data is available from Bluetooth (Phone to ESP32)
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());    // Read one byte from Bluetooth and send it to Serial Monitor
  }

  delay(20); 
}