void PrintDBTP(){
  int a = analogRead(pinTempSensor);
    float R = 1023.0/a-1.0;
    R = R0*R;
    temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
   }
}

void IRAM_ATTR flow () // Interrupt function
{
   flow_frequency++;
   isShower=true;
   ShowerStop=millis();
}

