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
    digitalWrite(MOTORA_PINS[0], HIGH);
    digitalWrite(MOTORB_PINS[0], HIGH);
    return;
}

void goBackwards()
{
    turnOffMotorPins();
    digitalWrite(MOTORA_PINS[1], HIGH);
    digitalWrite(MOTORB_PINS[1], HIGH);
    return;
}

void goLeftForward()
{
    turnOffLeftMotorPins();
    digitalWrite(MOTORA_PINS[0], HIGH);
    return;
}

void goLeftBackwards()
{
    turnOffLeftMotorPins();
    digitalWrite(MOTORA_PINS[1], HIGH);
    return;
}

void goRightForward()
{
    turnOffRightMotorPins();
    digitalWrite(MOTORB_PINS[0], HIGH);
    return;
}

void goRightBackwards()
{
    turnOffRightMotorPins();
    digitalWrite(MOTORB_PINS[1], HIGH);
    return;
}

void goForwardWithPID(int adj)
{
    int l_velo = START_VELO - adj;
    int r_velo = START_VELO + adj;

    if (l_velo > 0)
    {
        /*Avance el motor izquierdo hacia adelante con l_velo de rpm*/
        setLeftMotorSpeed(l_velo);
        goLeftForward();
    }
    else
    {
        /*Avance el motor izquierdo hacia atras con -l_velo de rpm*/
        setLeftMotorSpeed(-1 * l_velo);
        goLeftBackwards();
    }

    if (r_velo > 0)
    {
        /*Avance el motor izquierdo hacia adelante con r_velo de rpm*/
        setRightMotorSpeed(r_velo);
        goRightForward();
    }
    else
    {
        /*Avance el motor izquierdo hacia atras con -r_velo de rpm*/
        setRightMotorSpeed(-1 * r_velo);
        goRightBackwards();
    }

    return;
}