#ifndef MBED_LIGHTSENSOR_H
#define MBED_LIGHTSENSOR_H
#define RI 10
#define VRef 3.3
#define LuxRel 500

#include "mbed.h"
#include <string>

class LightSensor
{
    public:
        LightSensor(PinName pin);
        string getLightCondition();
    private:
        string getClosestCondition(float lux, int i);
        AnalogIn _pin;
};

#endif