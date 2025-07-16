#define BUTTON 4

void setup() 
{
  pinMode(BUTTON,INPUT);// Set Button as Input
  Serial.begin(9600);// Initialize Serial Monitor
}

void loop() 
{
  if(digitalRead(BUTTON)==HIGH)// If BUTTON press, Print HIGH on Serial Monitor
  Serial.println("HIGH");
  else
  Serial.println("LOW");// Print LOW on Serial Monitor
  
  delay(500);
}
