#include "DHT.h"
#define DHT11_PIN 2
DHT dht11(DHT11_PIN, DHT11);

#include <SoftwareSerial.h>
SoftwareSerial XBee(6,7);


void setup() {
XBee.begin(9600);
pinMode(A0,INPUT);
dht11.begin();

}

void loop() {

float humi = dht11.readHumidity();
float tempC = dht11.readTemperature();

XBee.print("#");
XBee.print(analogRead(A0));
XBee.print("#");
XBee.print(tempC);
XBee.print("#");
XBee.print(humi);


delay(2000);
}
