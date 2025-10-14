#ifndef UTILS_H_
#define UTILS_H_

#include "../../include/globalVars.h"
void activateBuzzer(void);
void printOutputMessage(Element, Side);
void turnOffMotorPins(void);
void turnOffAllPins(void);
float getUt(void);
int controlPID(float, float);

#endif