//Include
#include "mbed.h"
#include "ThisThread.h"
#include "LightSensor.h"
#include <iostream>
#include <string>
//Defines
#define RI 10000
#define VRef 3.3
#define LuxRel 500
// main() runs in its own thread in the OS

LightSensor lightSensor(A0);


int main()
{
    printf("hola\n");
    while (true) {
        printf("Now this is the light condition here: %s.\n", lightSensor.getLightCondition().c_str());
        ThisThread::sleep_for(2000ms);
        //Poner thread en pausa
    }
}
