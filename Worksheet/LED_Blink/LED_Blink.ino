#define LED_PIN 2

void setup()
{
  pinMode(LED_PIN,OUTPUT);// Set LED as Output
}

void loop()
{
  digitalWrite(LED_PIN,HIGH);// Turn On LED
  delay(500);
  digitalWrite(LED_PIN,LOW);// Turn Off LED
  delay(500);
}