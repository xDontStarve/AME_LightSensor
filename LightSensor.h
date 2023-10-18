#ifndef MBED_LIGHTSENSOR_H
#define MBED_LIGHTSENSOR_H
#define RI 10000
#define VRef 3.3
#define LuxRel 500

#include "mbed.h"
#include <string>

class LightSensor
{
    public:
        string getLightCondition(float readValue);
    private:
        string getClosestCondition(float lux, int i)
}

#endif