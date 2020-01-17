/*
  Written by Ilya Team
  Content ; Sensor Management Arduino libraries used by the ino main programme

*/

#ifndef Sensor_h
#define Sensor_h

#ifndef Arduino_h
  #include <Arduino.h>
#endif
#include <math.h>

class Sensor
{
  public:
    //Sensor functions
    void PrintDBTP();
    void IRAM_ATTR flow ();

    bool isShower;

    

  private:
    //Sensors Variables 
    volatile int _flow_frequency; // Measures flow sensor pulses
    unsigned int _l_hour; // Calculated litres/hour
    float _temperature;
    unsigned long _currentTime;
    unsigned long _cloopTime;
    unsigned long _ShowerStop;
    const int B;               // B value of the thermistor no _<name> because it is a constant
    const int R0;           // R0 = 100k
    const int pinTempSensor;   // Grove - Temperature Sensor connect to A0
    
};
#endif