#include "DHT.h"
#define DHT11_PIN 2
DHT dht11(DHT11_PIN, DHT11);

#include <SoftwareSerial.h>
SoftwareSerial XBee(0,1);


void setup() {
XBee.begin(9600);
Serial.begin(9600);
pinMode(A0,INPUT);
dht11.begin();

}

void loop() {

float humi = dht11.readHumidity();
float tempC = dht11.readTemperature();

Serial.print("luminosité =");
Serial.println(analogRead(A0));
Serial.print("température =");
Serial.print(tempC);
Serial.println(" °C");
Serial.print("humidité =");
Serial.println(humi);
Serial.println("---------------------");

XBee.write("test");

delay(2000);
}
