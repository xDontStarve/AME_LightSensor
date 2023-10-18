#include "LightSensor.h"
#include "mbed.h"
#include <string>

string LightSensor::getClosestCondition(float lux, int i){
    float rest1, rest2;
    rest1 = minValues[i] - lux;
    rest2 = lux - maxValues[i-1];

    if (rest1 < rest2)
    {
        return lightConditions[i];
    }
    return lightConditions[i-1];
    
}

string LightSensor::getLightCondition(float readValue){
     int i=0;
    float lux=NULL;
    //First we calculated the quantity of light
    lux = (((VRef*LuxRel)*readValue)-LuxRel)/RI;

    //Second we check if the lux value is inside of an acceptable rank if no we return direct one message
    if (lux < minValues[0]) return lightConditions[0];
    if (lux > maxValues[7]) return lightConditions[7];

    //If the lux value is inside an acceptable rank we check what type of light we have
    for (int i=0; i<8; i++){
        if (lux < maxValues[i]){
            if (lux > minValues[i])
                return lightConditions[i];
            else
                return getClosestCondition(lux, i); //This is only in case we have and error 
        }
    }

    return "Read Error";
}