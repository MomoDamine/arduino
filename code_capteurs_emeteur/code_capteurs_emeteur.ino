#include <SoftwareSerial.h>
SoftwareSerial xbee(3, 4);
#include <DHT.h>


// Définition des broches et du type de capteur DHT et constante
#define DHTPIN 2      // Broche de connexion du capteur DHT11
#define DHTTYPE DHT11 // Type de capteur DHT
int valeurLuminosite;
float temperature;
float humidite;
// Initialisation du capteur DHT
DHT dht(DHTPIN, DHTTYPE);


// Définition de la broche du capteur de lumière
const int CAPTEUR_LUMIERE = A0;

void setup()
{
    xbee.begin(9600);                 
    Serial.begin(9600);                     
// Initialisation de la communication série
  Serial.begin(9600);


  // Démarrage du capteur DHT
  dht.begin();


  // Configuration de la broche pour le capteur de lumière
  pinMode(CAPTEUR_LUMIERE, INPUT);

}
 
/***************************************
*  MAIN LOOP
***************************************/
 
void loop()
{
  // Lecture des données du capteur DHT
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();


  // Lecture des données du capteur de lumière
  int valeurLuminosite = analogRead(CAPTEUR_LUMIERE);






  // Pause avant la prochaine lecture
  delay(2000);
  Serial.println(valeurLuminosite);
  Serial.println(humidite);
  Serial.println(temperature);
  xbee.println(valeurLuminosite);
  xbee.println(humidite);
  xbee.println(temperature);
  delay(300);
}