/*
  Written by Ilya Team
  Content ; Functions to write ID of card and SSID/PASSWORD of wifi 
            in permanent memory

*/

#include "EEPROMESP.h"


void EEPROMESP::writeString(char add,String data)
{
    _size = data.length();
    int i; 
    for(i=0;i<_size;i++)
    {
    EEPROM.write(add+i,data[i]);
    }
    EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
    EEPROM.commit();
}


String EEPROMESP::read_String(char add)
{
  _k=EEPROM.read(add);
  while(_k != '\0' && _len<500)   //Read until null character
  {    
    _k=EEPROM.read(add+_len);
    _data[_len]=_k;
    _len++;
  }
  _data[_len]='\0';
  return String(_data);
}