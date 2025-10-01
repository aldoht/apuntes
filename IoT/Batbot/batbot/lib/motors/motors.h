#ifndef MOTORS_H_
#define MOTORS_H_

#include "../../include/globalVars.h"
void setLeftMotorSpeed(int);
void setRightMotorSpeed(int);
void turnCar(Side);
void goForward(void);
void goBackwards(void);
extern void turnOffMotorPins(void);
extern void printOutputMessage(Element, Side);

#endif