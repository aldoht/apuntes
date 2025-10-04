#include "testing.h"
#include "../../include/globalVars.h"

void testMotors() {
    Serial.println("Going forward.");
    goForward();
    delay(TURN_TIME);
    Serial.println("Turning left.");
    turnCar(Side::LEFT);
    delay(TURN_TIME);
    Serial.println("Turning right.");
    turnCar(Side::RIGHT);
    delay(TURN_TIME);
    Serial.println("Going backwards.");
    goBackwards();
    delay(TURN_TIME);
    Serial.println("Stopping.");
    turnOffMotorPins();
    delay(TURN_TIME);
    return;
}

void testBuzzer() {
    for (int i = 32; i <= MAX_ANALOG+1; i *= 2) {
        analogWrite(BUZZER_PIN, i);
        delay(1000);
        analogWrite(BUZZER_PIN, 0);
    }
    return;
}

void testSensor() {
    turnSensor(Side::LEFT);
    delay(1000);
    readDistance();
    delay(2000);
    turnSensor(Side::FRONT);
    delay(1000);
    readDistance();
    delay(2000);
    turnSensor(Side::RIGHT);
    delay(1000);
    readDistance();
    delay(2000);
    return;
}

void testMotorsSpeeds() {
    int i = 0, j = MAX_ANALOG;
    goForward();
    while (i <= MAX_ANALOG) {
    setLeftMotorSpeed(i);
    setRightMotorSpeed(j);
    i += 20;
    j -= 20;
    delay(500);
    }
    return;
}

/* Test for reading distance and controlling the motors directions */
void test1() {
    float dist = readDistance();
    if (dist < DESIRED_DISTANCE) {
    goBackwards();
    } else {
    goForward();
    }
}

/* Test for changing the motors' rpm: left first, then right */
void test2() {
    int i = 0;
    turnCar(Side::RIGHT);
    while (i <= MAX_ANALOG) {
    setLeftMotorSpeed(i);
    i += 20;
    delay(300);
    }
    turnCar(Side::LEFT);
    while (i >= 0) {
    setRightMotorSpeed(i);
    i -= 20;
    delay(300);
    }
    turnOffMotorPins();
    return;
}  