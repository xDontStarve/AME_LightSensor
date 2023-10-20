#ifndef MBED_LIGHTSENSOR_H
#define MBED_LIGHTSENSOR_H
#define RI 10000
#define VRef 3.3
#define LuxRel 500

#include "mbed.h"
#include <string>

string lightConditions[8]={"Pitch Dark", "Very Dark", "Dark Indoors", "Corridor Area/Toilets", "Rest Room", "Entrances/Exits/Canteens", "School Assebly/Halls", "Reading"};
float minValues[8]={0.4, 6, 51, 140, 155, 196, 296, 326};
float maxValues[8]={5, 50, 95, 145, 195, 295, 325, 355};

class LightSensor
{
    public:
        LightSensor(PinName pin);
        string getLightCondition();
    private:
        string getClosestCondition(float lux, int i);
        AnalogIn _pin;
}

#endif