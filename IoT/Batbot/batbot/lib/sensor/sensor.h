#ifndef SENSOR_H_
#define SENSOR_H_

#include "../../include/globalVars.h"
void turnSensor(Side);
void turnSensorByDeg(int);
float readDistance(void);
extern void printOutputMessage(Element, Side);

#endif