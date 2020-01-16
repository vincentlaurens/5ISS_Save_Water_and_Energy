/*
  Written by Ilya Team
  Content ; Sensor Management Arduino libraries used by the ino main programme

*/

#ifndef Sensor_h
#define Sensor_h

#include <math.h>

class Sensor
{
  public:
    
    //Sensors Variables 
    volatile int flow_frequency; // Measures flow sensor pulses
    unsigned int l_hour; // Calculated litres/hour
    float temperature;
    unsigned long currentTime;
    unsigned long cloopTime;
    const int B = 4275;               // B value of the thermistor
    const int R0 = 100000;            // R0 = 100k
    const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

    //Sensor functions
    void PrintDBTP();
    void IRAM_ATTR flow ();
    

#endif