
#include <LiquidCrystal.h>

// Pin definitions
const int trigPin = 8;
const int echoPin = 7;
const int red = 6;
const int green = 10;
const int yellow = 9;

// other variables
long time;
long distance;

//Creating an LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Pin modes are setting
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  // LCD starting
  lcd.begin(16, 2);
  
  // Starting serial communication
  Serial.begin(9600);
}

void loop() {
  // distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  time = pulseIn(echoPin, HIGH);
  distance = (time / 2) * 0.0343;

  //Printing distance to LCD and serial monitor
  writeDistance(distance);

  // Checking LEDs
  controlLED(distance);
  
delay(125);
}

void writeDistance(long distance) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
}
void controlLED(long distance) {
  if (distance > 0 && distance <= 20) {
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(yellow, 0);
  } else if (distance > 20 && distance <= 40) {
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(yellow, 255);
  } else {
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(yellow, 0);
  }
}
