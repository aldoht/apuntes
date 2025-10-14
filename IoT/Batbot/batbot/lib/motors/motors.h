#ifndef MOTORS_H_
#define MOTORS_H_

#include "../../include/globalVars.h"
void setLeftMotorSpeed(int);
void setRightMotorSpeed(int);
void turnCar(Side);
void goForward(void);
void goBackwards(void);
void goLeftForward(void);
void goLeftBackwards(void);
void goRightForward(void);
void goRightBackwards(void);
void goForwardWithPID(int);
extern void turnOffMotorPins(void);
extern void printOutputMessage(Element, Side);
extern void turnOffLeftMotorPins(void);
extern void turnOffRightMotorPins(void);

#endif