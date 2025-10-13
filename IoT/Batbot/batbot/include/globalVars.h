#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#include <Arduino.h>
#define DESIRED_DISTANCE 5.0
#define DIFF_TIME 100
#define TURN_TIME 100
#define K_P 100.0
#define K_I 0.0
#define K_D 0.0
#define MAX_ANALOG 255
#define BUZZER_POWER 100
#define BUZZER_TIME 400
#define BUZZER_PIN 0
#define L_ECHO_PIN 5
#define L_TRIGGER_PIN 4
#define R_ECHO_PIN 6
#define R_TRIGGER_PIN 7
#define C_ECHO_PIN 3
#define C_TRIGGER_PIN 2
#define ENABLEA_PIN 10
#define ENABLEB_PIN 11
const int MOTORA_PINS[2] = {13, 8};
const int MOTORB_PINS[2] = {9, 12};
extern float sensorLeftDistance;
extern float sensorRightDistance;
extern float sensorCenterDistance;
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