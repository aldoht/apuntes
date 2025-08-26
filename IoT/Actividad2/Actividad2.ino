#include <Servo.h>
Servo SERVOMOTOR;
const byte POTENTIOMETER_PIN = A0;
const byte SERVO_PIN = 2;
const byte LED_PINS[9] = {3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup()
{
  SERVOMOTOR.attach(SERVO_PIN);
  Serial.begin(9600);
  for (byte i = 0; i < 9; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  turnOffLeds();
}

void loop()
{
  int angle = moveServo();
  useLeds(angle);
  delay(2000);
  turnOffLeds();
}

int moveServo() {
  int value = analogRead(POTENTIOMETER_PIN);
  int ang = map(value, 0, 1023, 0, 180);
  SERVOMOTOR.write(ang);
  Serial.print("El valor del potenciometro es: ");
  Serial.print(value);
  Serial.print(" El angulo del eje es: ");
  Serial.println(ang);
  return ang;
}

void useLeds(int ang) {
  if (ang > 0) {
    int temp = 0;
    while (ang > temp) {
      digitalWrite(temp / 20 + 3, HIGH);
      temp += 20;
    }
  }
}

void turnOffLeds() {
  for (byte i = 0; i < 9; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}