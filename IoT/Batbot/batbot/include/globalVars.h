#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#include <Arduino.h>
#define DESIRED_DISTANCE 15.0
#define DIFF_TIME 100
#define TURN_TIME 100
#define K_P 100.0
#define K_I 0.0
#define K_D 0.0
#define MAX_ANALOG 255
#define BUZZER_POWER 100
#define BUZZER_TIME 400
#define BUZZER_PIN 3
#define ECHO_PIN 12
#define TRIGGER_PIN 13
#define ENABLE1_PIN 6
#define ENABLE2_PIN 3
const int MOTOR1_PINS[2] = {2, 4};
const int MOTOR2_PINS[2] = {5, 7};
extern float sensorDistance;
extern float error;
extern float prevError;
extern float sumError;
extern float ut;

enum Side
{
	LEFT,
	RIGHT,
	FRONT
};
enum Element
{
	SENSOR,
	CAR
};

#endif