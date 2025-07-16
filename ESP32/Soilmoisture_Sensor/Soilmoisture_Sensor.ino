#define MOISTURE_PIN 34  // Analog pin connected to soil moisture sensor

void setup() {
  Serial.begin(9600);  // Start serial Monitor communication
}

void loop() {
  int sensorValue = analogRead(MOISTURE_PIN);  // Read analog value (0–4095)

  // Convert raw value to percentage (0 = wet, 4095 = dry)
  int moisturePercent = map(sensorValue, 0, 4095, 100, 0);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  delay(1000);  
}