#include "sensor.h"
#include "../../include/globalVars.h"

float readDistance(Side s)
{
    int t_pin, e_pin = 0;
    String side = "?";
    switch (s)
    {
    case 0:
        t_pin = L_TRIGGER_PIN;
        e_pin = L_ECHO_PIN;
        side = "left";
        break;
    case 1:
        t_pin = R_TRIGGER_PIN;
        e_pin = R_ECHO_PIN;
        side = "right";
        break;
    case 2:
        t_pin = C_TRIGGER_PIN;
        e_pin = C_ECHO_PIN;
        side = "center";
        break;
    default:
        break;
    }

    digitalWrite(t_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(t_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(t_pin, LOW);

    int pulseTime = pulseIn(t_pin, HIGH);
    float soundDistance = pulseTime * 0.034 / 2;

    if (soundDistance < 0)
    {
        soundDistance *= -1;
    }

    Serial.print("Distance in ");
    Serial.print(side);
    Serial.print(" sensor: ");
    Serial.print(soundDistance);
    Serial.print(" cm");
    Serial.println("");

    return soundDistance;
}