const int analog_pin = 34;  // Analog input pin connected to potentiometer

void setup() {
  Serial.begin(115200);    // Initialize Serial Monitor
}

void loop() {
  int value = analogRead(analog_pin);  // Read analog value (0–4095)
  
  Serial.print("Potentiometer value: ");
  Serial.println(value);               // Print raw ADC value

  delay(1000);                       

  // Convert ADC value to voltage (based on 3.3V reference)
  Serial.println((value * 3.3) / 4095.00);
}