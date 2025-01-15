#define LDR A1 // composante photoresistor sur la pin A1

int value;
 
void setup() {
   // initialise la communication avec le PC
   Serial.begin(9600);

   // initialise les broches
   pinMode(LDR, INPUT);
}
 
void loop() {
   // mesure la tension sur la broche A1
   value= 1023-analogRead(LDR);
   Serial.println(value);

   delay(1000);
}
