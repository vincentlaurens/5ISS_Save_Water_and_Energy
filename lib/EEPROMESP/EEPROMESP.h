/*
  Written by Ilya Team
  Content ; persistant Memory  library used by the ino main programme

*/

#ifndef EEPROMESP_h
#define EEPROMESP_h

#ifndef Arduino_h
  #include <Arduino.h>
#endif

#ifndef EEPROM_h
 #include<EEPROM.h>
#endif

    class EEPROMESP {
        public:
            /** 
                Create A FUNCTION which launch.
            */
            void writeString(char add,String data);
            String read_String(char add);
        private:
            int _size;
            char _data[100]; //Max 100 Bytes
            int _len;
            unsigned char _k;
    };


#endif
