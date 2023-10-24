#include "LightSensor.h"
#include "mbed.h"
#include <string>

string lightConditions[8]={"Pitch Dark", "Very Dark", "Dark Indoors", "Corridor Area/Toilets", "Rest Room", "Entrances/Exits/Canteens", "School Assebly/Halls", "Reading"};
float minValues[8]={0.4, 6, 51, 140, 155, 196, 296, 326};
float maxValues[8]={5, 50, 95, 145, 195, 295, 325, 355};

LightSensor::LightSensor(PinName pin) : _pin(pin){}

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

std::string LightSensor::getLightCondition(){
    int i=0;
    float lux=NULL;
    float readValue = VRef*_pin.read_u16()/65535;
    //First we calculated the quantity of light
    lux = (((VRef*LuxRel)*readValue)-LuxRel)/RI;
    printf("Read value: %f, Lux value: %f\n", readValue, lux);

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