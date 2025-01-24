#include <DHT.h>

// Configuration pour le capteur DHT11
#define DHTPIN 2      // Pin de connexion du capteur DHT
#define DHTTYPE DHT11 // Type du capteur (DHT11 ou DHT22)
DHT dht(DHTPIN, DHTTYPE);

// Configuration pour la photorésistance
const int lightPin = A0; // Pin analogique connecté à la photorésistance
int lightValue = 0;      // Variable pour stocker la lecture de la lumière

void setup() {
  Serial.begin(9600); // Initialisation de la communication série
  dht.begin();        // Initialisation du capteur DHT
  Serial.println("Lecture des données : DHT11 et photorésistance...");
}

void loop() {
  // === Lecture des données du capteur DHT11 ===
  float humidity = dht.readHumidity();      // Lecture de l'humidité
  float temperature = dht.readTemperature(); // Lecture de la température

  // Vérification des erreurs de lecture pour le DHT11
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Erreur de lecture du capteur DHT !");
  } else {
    // Affichage des données DHT11
    Serial.print("Humidité: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Température: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  // === Lecture des données de la photorésistance ===
  lightValue = analogRead(lightPin); // Lecture de la valeur analogique
  float lightPercentage = (lightValue / 1023.0) * 100; // Conversion en pourcentage

  // Affichage des données de luminosité
  Serial.print("Valeur brute de luminosité : ");
  Serial.print(lightValue);
  Serial.print(" | Luminosité estimée : ");
  Serial.print(lightPercentage);
  Serial.println(" %");

  // Pause avant la prochaine lecture
  delay(2000); // Lecture toutes les 2 secondes
}
