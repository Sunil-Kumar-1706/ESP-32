#define LED 2
#define BUTTON 4

void setup() {
  pinMode(BUTTON,INPUT);//Button as Input
  pinMode(LED,OUTPUT);//LED as Output
}

void loop() {
 if(digitalRead(BUTTON)==HIGH)
 {
  digitalWrite(LED,HIGH);
  delay(500);
 }
 else
 {
  digitalWrite(LED,LOW);
  delay(500);
 }

}
