#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#include <Arduino.h>
#include <Servo.h>
#define DESIRED_DISTANCE 15.0
#define DIFF_TIME 100
#define TURN_TIME 100
#define K_P 100.0
#define K_I 0.0
#define K_D 0.0
#define BUZZER_POWER 100
#define BUZZER_TIME 400
#define MAX_ANALOG 255
const uint8_t MOTOR1_PINS[2] = {10, 11};
const uint8_t MOTOR2_PINS[2] = {12, 13};
#define BUZZER_PIN 3
#define ECHO_PIN 5
#define TRIGGER_PIN 6
#define SERVO_PIN 9
#define ENABLE1_PIN 7
#define ENABLE2_PIN 8
extern const uint8_t MOTOR1_PINS[2];
extern const uint8_t MOTOR2_PINS[2];
extern Servo SERVOMOTOR;
extern float sensorDistance;
extern float error;
extern float prevError;
extern float sumError;
extern float ut;

enum Side {
	LEFT,
	RIGHT,
	FRONT
};
enum Element {
	SENSOR,
	CAR
};

#endif