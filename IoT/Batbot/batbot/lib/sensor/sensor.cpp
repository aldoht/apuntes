#include "sensor.h"
#include "../../include/globalVars.h"

float readDistance()
{
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    int pulseTime = pulseIn(ECHO_PIN, HIGH);
    float soundDistance = pulseTime * 0.034 / 2;

    if (soundDistance < 0)
    {
        soundDistance *= -1;
    }

    Serial.print("Distance: ");
    Serial.print(soundDistance);
    Serial.print(" cm");
    Serial.println("");

    return soundDistance;
}