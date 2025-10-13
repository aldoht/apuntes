#include "motors.h"

void setLeftMotorSpeed(int speed)
{
    if (speed > MAX_ANALOG)
    {
        speed = MAX_ANALOG;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    analogWrite(ENABLEA_PIN, speed);
    return;
}

void setRightMotorSpeed(int speed)
{
    if (speed > MAX_ANALOG)
    {
        speed = MAX_ANALOG;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    analogWrite(ENABLEB_PIN, speed);
    Serial.println(speed);
    return;
}

void turnCar(Side s)
{
    turnOffMotorPins();
    delay(500);
    printOutputMessage(Element::CAR, s);

    switch (s)
    {
    case 0:
        digitalWrite(MOTORB_PINS[0], HIGH);
        break;
    case 1:
        digitalWrite(MOTORA_PINS[0], HIGH);
        break;
    default:
        break;
    }

    return;
}

void goForward()
{
    turnOffMotorPins();
    delay(500);
    digitalWrite(MOTORA_PINS[0], HIGH);
    digitalWrite(MOTORB_PINS[0], HIGH);
    return;
}

void goBackwards()
{
    turnOffMotorPins();
    delay(500);
    digitalWrite(MOTORA_PINS[1], HIGH);
    digitalWrite(MOTORB_PINS[1], HIGH);
    return;
}