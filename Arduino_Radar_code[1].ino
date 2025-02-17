#include <Servo.h>

#define trigPin 8
#define echoPin 9

long duration;
int distance;

Servo myservo;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {
  int i;
  for (i = 1; i <= 179; i++) {
    myservo.write(i);
    delay(15);
    calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (i = 179; i >= 1; i--) {
    myservo.write(i);
    delay(15);
    calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}