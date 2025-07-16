#include "DHT.h"//include DHT sensor Library

#define DHTPIN 4          
#define DHTTYPE DHT22  //Specify the DHT sensor model (DHT22)

DHT dht(DHTPIN, DHTTYPE);//Create a DHT object using specified pin and type

void setup() {
  Serial.begin(9600);
  dht.begin();//Initialize the DHT sensor
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();//Read Humidity
  float temperature = dht.readTemperature(); //Read Temperature

  if (isnan(humidity) || isnan(temperature)) {  //Check if any reads failed
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);//Humidity value

  Serial.print("Temperature: ");
  Serial.print(temperature);//Temperature value
}
