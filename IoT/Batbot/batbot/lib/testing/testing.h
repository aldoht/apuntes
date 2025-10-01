#ifndef TESTING_H_
#define TESTING_H_

#include "../../include/globalVars.h"
void testMotors(void);
void testBuzzer(void);
void testSensor(void);
void testMotorsSpeeds(void);
/* Test for reading distance and controlling the motors directions */
void test1(void);
/* Test for changing the motors' rpm: left first, then right */
void test2(void);
extern void goForward(void);
extern void turnCar(Side);
extern void goBackwards();
extern void turnOffMotorPins();
extern void turnSensor(Side);
extern float readDistance(void);
extern void setLeftMotorSpeed(int);
extern void setRightMotorSpeed(int);

#endif