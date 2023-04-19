// Déclaration des broches
const int boutonPin = 2; // Broche de l'interrupteur
const int ledPin = 13; // Broche de la LED
const int buzzerPin = 10; // Broche du buzzer

// Variables globales
int boutonEtat = 0;
int derniereEtatBouton = 0;
bool sonnerieActivee = false;
String codeAttendu = "1234"; // Code attendu pour arrêter la sonnerie
String codeEntre = ""; // Code entré par l'utilisateur

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(boutonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialisation de la communication série
}

void loop() {
  // Lecture de l'état du bouton
  boutonEtat = digitalRead(boutonPin);

  // Si le bouton est appuyé et la sonnerie n'est pas active
  if (boutonEtat == HIGH && derniereEtatBouton == LOW && !sonnerieActivee) {
    digitalWrite(ledPin, HIGH); // Allumer la LED
    tone(buzzerPin, 1000, 1000); // Démarrer la sonnerie du buzzer
    sonnerieActivee = true; // Marquer la sonnerie comme active
  }

  // Si la sonnerie est active et une commande est disponible sur la communication série
  if (sonnerieActivee && Serial.available() > 0) {
    char caractere = Serial.read(); // Lire le caractère entré

    // Si le caractère est un chiffre
    if (isdigit(caractere)) {
      codeEntre += caractere; // Ajouter le chiffre au code entré

      // Si le code entré correspond au code attendu
      if (codeEntre == codeAttendu) {
        digitalWrite(ledPin, LOW); // Éteindre la LED
        noTone(buzzerPin); // Arrêter la sonnerie du buzzer
        sonnerieActivee = false; // Marquer la sonnerie comme inactive
        codeEntre = ""; // Réinitialiser le code entré
      }
    } else {
      codeEntre = ""; // Réinitialiser le code entré si le caractère entré n'est pas un chiffre
    }
  }

  derniereEtatBouton = boutonEtat; // Mémoriser l'état précédent du bouton
}
