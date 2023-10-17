#include "mbed.h"
#include <iostream>
#include <string>
// main() runs in its own thread in the OS
string lightConditions[8]={"Pitch Dark", "Very Dark", "Dark Indoors", "Corridor Area/Toilets", "Rest Room", "Entrances/Exits/Canteens", "School Assebly/Halls", "Reading"};
float minValues[8]={0.4, 6, 51, 140, 155, 196, 296, 326};
float maxValues[8]={5, 50, 95, 145, 195, 295, 325, 355};

string getClosestCondition(float lux, int i){
    return "";
}

string getLightCondition(float lux){

    int i=0;

    if (lux < 0.4) return lightConditions[0];

    for (int i=0; i<8; i++){
        if (lux < maxValues[i]){
            if (lux > minValues[i])
                return lightConditions[i];
            else
                return getClosestCondition(lux, i);
        }
    }

    return "Read Error";
}

int main()
{
    while (true) {

    }
}

