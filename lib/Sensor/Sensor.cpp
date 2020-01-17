/*
  Written by Ilya Team
  Content ; Energy library used by the ino main programme
*/
#include "Sensor.h"


void Sensor::PrintDBTP(){
  int a = analogRead(pinTempSensor);
  float R = 1023.0/a-1.0;
    R = R0*R;
    _temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
   _currentTime = millis();
   // Every second, calculate and print litres/hour
   if(_currentTime >= (_cloopTime + 1000))
   {
      _cloopTime = _currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      _l_hour = (_flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      _flow_frequency = 0; // Reset Counter
   }
}

void IRAM_ATTR Sensor::flow () // Interrupt function
{
   _flow_frequency++;
   isShower=true;
   _ShowerStop=millis();
}

