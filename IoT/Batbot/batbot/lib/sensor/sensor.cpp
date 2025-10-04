#include "sensor.h"
#include "../../include/globalVars.h"

void turnSensor(Side s) {
    printOutputMessage(Element::SENSOR, s);
    switch (s) {
    case 0:
        SERVOMOTOR.write(180);
        break;
    case 1:
        SERVOMOTOR.write(0);
        break;
    case 2:
        SERVOMOTOR.write(90);
        break;
    default:
        break;
    }

    return;
}

void turnSensorByDeg(int deg) {
    Serial.print("Turning sensor ");
    Serial.print(deg);
    Serial.println(" degrees.");
    SERVOMOTOR.write(deg);
    return;
}

float readDistance() {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    int pulseTime = pulseIn(ECHO_PIN, HIGH);
    float soundDistance = pulseTime*0.034 / 2;

    if (soundDistance < 0) {
        soundDistance *= -1;
    }

    Serial.print("Distance: ");
    Serial.print(soundDistance);
    Serial.print(" cm");
    Serial.println("");

    return soundDistance;
}