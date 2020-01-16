/*
  Written by Ilya Team
  Content ; persistant Memory  library used by the ino main programme

*/

#ifndef EEPROM_ESP
#def EEPROM_ESP

 #include<EEPROM.h>

    class EEPROM_ESP {
        public:

            /**
             * Create Variables
             * 
             * 
             * */

            int _size;
            char _data[100]; //Max 100 Bytes
            int _len=0;
            unsigned char _k;


            /** 
                Create A FUNCTION which launch.
            */
            void writeString(char add,String data)
            String read_String(char add)

            
    };


#endif
