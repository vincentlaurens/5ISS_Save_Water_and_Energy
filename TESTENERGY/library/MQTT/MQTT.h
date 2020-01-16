/*
  Written by Ilya Team
  Content ; All Arduino MQTT used by the ino main programme

*/

#ifndef MQTT_h
#define MQTT_h

#include <PubSubClient.h>
#include<ArduinoJson.h>


// Update these with values suitable for your network.
#define mqtt_port 1883
#define MQTT_USER "mickaelcommerot1@gmail.com"
#define MQTT_PASSWORD "ilya"
#define MQTT_SERIAL_PUBLISH_CH "mickaelcommerot1@gmail.com/ilya"
#define MQTT_SERIAL_ALERT "mickaelcommerot1@gmail.com/alert"
#define MQTT_SERIAL_RECEIVER_CH "mickaelcommerot1@gmail.com/ilya"


class MQTT {
  public:

    /**
     * Variable definition 
     * */

    PubSubClient client(wifiClient);


    /** 
        Create A FUNCTION which launch.
    */
    //void callback(char* topic, byte *payload, unsigned int length);


};

    



#endif