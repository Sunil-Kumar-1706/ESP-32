const int LED=2;
const int touch_pin=14;
int touch_val,thresh_val=50;
  

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);// LED pin as output
  delay(500);
}

void loop() {
  touch_val=touchRead(touch_pin); // reading the value of touch pin
  Serial.println(touch_val);
  if(touch_val < thresh_val)// if value is less than 50 then touch is detected
  digitalWrite(LED,HIGH);//turn on LED
  else
  digitalWrite(LED,LOW);

  delay(100);

}
