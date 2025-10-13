#include "utils.h"
#include "../../include/globalVars.h"

void activateBuzzer()
{
    analogWrite(BUZZER_PIN, BUZZER_POWER);
    delay(BUZZER_TIME);
    analogWrite(BUZZER_PIN, 0);
    return;
}

void printOutputMessage(Element e, Side s)
{
    String strSide = "";
    switch (s)
    {
    case 0:
        strSide = "left.";
        break;
    case 1:
        strSide = "right.";
        break;
    case 2:
        strSide = "front.";
        break;
    default:
        break;
    }
    String strElement = (e == 0) ? "sensor " : "car";
    Serial.print("Turning ");
    Serial.print(strElement);
    Serial.print("to the ");
    Serial.println(strSide);
    return;
}

void turnOffMotorPins()
{
    digitalWrite(MOTOR1_PINS[0], LOW);
    digitalWrite(MOTOR1_PINS[1], LOW);
    digitalWrite(MOTOR2_PINS[0], LOW);
    digitalWrite(MOTOR2_PINS[1], LOW);
    return;
}

void turnOffAllPins()
{
    turnOffMotorPins();
    analogWrite(BUZZER_PIN, 0);
    digitalWrite(ECHO_PIN, LOW);
    digitalWrite(TRIGGER_PIN, LOW);
    return;
}

float getUt()
{
    return K_P * error + K_I * sumError + K_D * (error - prevError);
}