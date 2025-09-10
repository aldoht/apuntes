#include <Servo.h>

/* Declaracion de constantes */
const byte MOTOR1_PINS[2] = {6, 7};
const byte MOTOR2_PINS[2] = {4, 5};
const byte ENABLE_PIN = 10;
const byte TRIGGER_PIN = 2;
const byte ECHO_PIN = 3;
const float speed = 0.5*255;

void setup() {
  pinMode(MOTOR1_PINS[0], OUTPUT);
  pinMode(MOTOR1_PINS[1], OUTPUT);
  pinMode(MOTOR2_PINS[0], OUTPUT);
  pinMode(MOTOR2_PINS[1], OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  disablePins();
  analogWrite(ENABLE_PIN, speed);
  Serial.begin(9600);
}

void loop() {
  /**/
}

void stop() {
  digitalWrite(MOTOR1_PINS[0], LOW);
  digitalWrite(MOTOR1_PINS[1], LOW);
  digitalWrite(MOTOR2_PINS[0], LOW);
  digitalWrite(MOTOR2_PINS[1], LOW);
}

void disablePins() {
  stop();
  digitalWrite(ENABLE_PIN, LOW);
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(ECHO_PIN, LOW);
}

