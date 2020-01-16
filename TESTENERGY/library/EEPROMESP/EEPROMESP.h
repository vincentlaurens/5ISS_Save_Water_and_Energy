/*
  Written by Ilya Team
  Content ; persistant Memory  library used by the ino main programme

*/

#ifndef EEPROMESP_h
#define EEPROMESP_h

#ifndef EEPROM_h
 #include<EEPROM.h>
#endif

    class EEPROMESP {
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
            void writeString(char add,String data);
            String read_String(char add);

            
    };


#endif
