#include "motors.h"

void setLeftMotorSpeed(int speed) {
    if (speed > MAX_ANALOG) { speed = MAX_ANALOG; }
    if (speed < 0) { speed = 0; }
    analogWrite(ENABLE1_PIN, speed);
    return;
}

void setRightMotorSpeed(int speed) {
    if (speed > MAX_ANALOG) { speed = MAX_ANALOG; }
    if (speed < 0) { speed = 0; }
    analogWrite(ENABLE2_PIN, speed);
    Serial.println(speed);
    return;
}

void turnCar(Side s) {
    turnOffMotorPins();
    delay(500);
    printOutputMessage(Element::CAR, s);

    switch (s) {
    case 0:
        digitalWrite(MOTOR2_PINS[0], HIGH);
        break;
    case 1:
        digitalWrite(MOTOR1_PINS[0], HIGH);
        break;
    default:
        break;
    }

    return;
}

void goForward() {
    turnOffMotorPins();
    delay(500);
    digitalWrite(MOTOR1_PINS[0], HIGH);
    digitalWrite(MOTOR2_PINS[0], HIGH);
    return;
}

void goBackwards() {
    turnOffMotorPins();
    delay(500);
    digitalWrite(MOTOR1_PINS[1], HIGH);
    digitalWrite(MOTOR2_PINS[1], HIGH);
    return;
}