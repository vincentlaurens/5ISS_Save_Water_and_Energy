void writeString(char add,String data)
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


String read_String(char add)
{
  int i;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+_len);
    _data[_len]=_k;
    _len++;
  }
  _data[_len]='\0';
  return String(_data);
}