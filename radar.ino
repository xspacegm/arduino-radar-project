#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 7;
const int redLedPin = 4;    // Kırmızı lamba Pin 4
const int greenLedPin = 5;  // Yeşil lamba Pin 5

long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  Serial.begin(9600);
  myServo.attach(11);
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 35000);
  distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  // 15'ten 165 dereceye tarama
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    
    checkObstacle(distance);

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  
  // 165'ten 15 dereceye geri dönüş
  for (int i = 165; i >= 15; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    
    checkObstacle(distance);

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

void checkObstacle(int dist) {
  // Eğer radarda 50 cm içinde bir nesne görünürse
  if (dist > 2 && dist <= 50) {
    digitalWrite(redLedPin, HIGH);   // Kırmızı LED'i yak
    digitalWrite(greenLedPin, LOW);  // Yeşil LED'i söndür
    tone(buzzerPin, 1000);           // Buzzer'ı öttür
  } 
  else {
    digitalWrite(redLedPin, LOW);    // Kırmızı LED'i söndür
    digitalWrite(greenLedPin, HIGH); // Yeşil LED'i sürekli (ful) yak
    noTone(buzzerPin);               // Buzzer'ı sustur
  }
}