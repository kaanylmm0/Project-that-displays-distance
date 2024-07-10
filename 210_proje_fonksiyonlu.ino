#include <LiquidCrystal.h>

// Pin tanımlamaları
const int trigPin = 8;
const int echoPin = 7;
const int kirmizi = 6;
const int yesil = 10;
const int sari = 9;

// Diğer değişkenler
long sure;
long uzaklik;

// LCD nesnesi oluşturma
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Pin modları ayarlanıyor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  
  // LCD başlatma
  lcd.begin(16, 2);
  
  // Seri haberleşmeyi başlatma
  Serial.begin(9600);
}

void loop() {
  // Mesafe ölçümü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  sure = pulseIn(echoPin, HIGH);
  uzaklik = (sure / 2) * 0.0343;

  // Mesafeyi LCD'ye ve seri monitöre yazdırma
  yazdirMesafe(uzaklik);

  // LED'leri kontrol etme
  kontrolLED(uzaklik);
  
delay(125);
}

void yazdirMesafe(long mesafe) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(mesafe);
  lcd.print(" cm");
  

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
 
}
void kontrolLED(long mesafe) {
  if (mesafe > 0 && mesafe <= 20) {
    analogWrite(kirmizi, 255);
    analogWrite(yesil, 0);
    analogWrite(sari, 0);
  } else if (mesafe > 20 && mesafe <= 40) {
    analogWrite(kirmizi, 0);
    analogWrite(yesil, 0);
    analogWrite(sari, 255);
  } else {
    analogWrite(kirmizi, 0);
    analogWrite(yesil, 255);
    analogWrite(sari, 0);
  }
}
