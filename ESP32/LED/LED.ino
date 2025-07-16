const int LED_PIN=2;

void setup() {
  pinMode(LED_PIN,OUTPUT);//Set LED_PIN as output
}

void loop() {
  digitalWrite(LED_PIN,HIGH);//Turn On LED
  delay(1000);//Wait 1 second
  digitalWrite(LED_PIN,LOW);//Turn Off LED
  delay(1000);//Wait 1 second
}
