/*
  Written by Ilya Team
  Content ; All Arduino MQTT used by the ino main programme

*/

#ifndef MQTT_h
#define MQTT_h

#ifndef Arduino_h
  #include <Arduino.h>
#endif
#ifndef PubSubClient_h
  #include <PubSubClient.h>
#endif
#ifndef ArduinoJson_h
  #include <ArduinoJSON.h>
#endif


// Update these with values suitable for your network.
#define MQTT_PORT 1883
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
    const char* mqtt_server = "maqiatto.com";

    // Function to parse data to JSON before sending it
    //JSON COnfig
    const int capacity = JSON_OBJECT_SIZE(2);
    StaticJsonDocument<capacity> Datadoc;
    StaticJsonDocument<2048> Objectdoc;
    StaticJsonDocument<1024> Datasdoc;
    JsonArray array = Datasdoc.to<JsonArray>();

    /** 
        Create A FUNCTION which launch.
    */
   // Send serialsized data to the broker
    void publishSerialData(char *serialData);
    //Run an interrupt to send data via the broker
    void callback(char* topic, byte *payload, unsigned int length);
    // Function to reestablish connexion with remote broker
    void reconnect();



};

    



#endif