#include "../include/globalVars.h"
Servo SERVOMOTOR;
float sensorDistance = 0.0;
float error = 0.0;
float prevError = 0.0;
float sumError = 0.0;
float ut = 0.0;
#include <utils.h>
#include <motors.h>
#include <sensor.h>
#include <testing.h>

void setup() {
	pinMode(MOTOR1_PINS[0], OUTPUT);
	pinMode(MOTOR1_PINS[1], OUTPUT);
	pinMode(MOTOR2_PINS[0], OUTPUT);
	pinMode(MOTOR2_PINS[1], OUTPUT);
	pinMode(BUZZER_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(SERVO_PIN, OUTPUT);
    pinMode(ENABLE1_PIN, OUTPUT);
    pinMode(ENABLE2_PIN, OUTPUT);

	turnOffAllPins();
	setLeftMotorSpeed(MAX_ANALOG);
    setRightMotorSpeed(MAX_ANALOG);
	
	SERVOMOTOR.attach(SERVO_PIN);

	Serial.begin(9600);
	// delay(2500);
}

void run() {
	turnOffMotorPins();
	sensorDistance = readDistance();
	if (sensorDistance != DESIRED_DISTANCE) {
		if (sensorDistance > DESIRED_DISTANCE) {
		turnCar(Side::RIGHT);
		delay(TURN_TIME);
		goForward();
		delay(200);
		turnCar(Side::LEFT);
		delay(TURN_TIME);
		}
		else {
		turnCar(Side::LEFT);
		delay(TURN_TIME);
		goForward();
		delay(200);
		turnCar(Side::RIGHT);
		delay(TURN_TIME);
		}
		
	}
	goForward();
	delay(DIFF_TIME);
}

void loop() {
	// run();
    goForward();
    delay(4000);
    // testSensor();
}