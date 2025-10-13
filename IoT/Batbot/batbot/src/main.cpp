#include "../include/globalVars.h"
float sensorLeftDistance = 0.0;
float sensorRightDistance = 0.0;
float sensorCenterDistance = 0.0;
float error = 0.0;
float prevError = 0.0;
float sumError = 0.0;
float ut = 0.0;
#include <utils.h>
#include <motors.h>
#include <sensor.h>
#include <testing.h>

void setup()
{
	pinMode(MOTOR1_PINS[0], OUTPUT);
	pinMode(MOTOR1_PINS[1], OUTPUT);
	pinMode(MOTOR2_PINS[0], OUTPUT);
	pinMode(MOTOR2_PINS[1], OUTPUT);
	pinMode(BUZZER_PIN, OUTPUT);
	pinMode(L_ECHO_PIN, INPUT);
	pinMode(L_TRIGGER_PIN, OUTPUT);
	pinMode(R_ECHO_PIN, INPUT);
	pinMode(R_TRIGGER_PIN, OUTPUT);
	pinMode(C_ECHO_PIN, INPUT);
	pinMode(C_TRIGGER_PIN, OUTPUT);
	pinMode(ENABLE1_PIN, OUTPUT);
	pinMode(ENABLE2_PIN, OUTPUT);

	turnOffAllPins();
	setLeftMotorSpeed(MAX_ANALOG);
	setRightMotorSpeed(MAX_ANALOG);

	Serial.begin(9600);
	// delay(2500);
}

void loop()
{
	goForward();
	delay(4000);
}