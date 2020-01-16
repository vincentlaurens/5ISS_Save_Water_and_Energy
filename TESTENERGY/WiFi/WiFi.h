/*
  Written by Ilya Team
  Content ; All Arduino libraries used by the ino main programme

*/

#ifndef WIFI
#def WIFI

  #ifndef WIFIMANAGER
    #include <WiFiManager.h>
  #endif

  #ifndef ESP8266WiFi
    #include <ESP8266WiFi.h>
  #endif



  class WiFiManager
  {
    public:
      // Update these with values suitable for your network.
      #define mqtt_port 1883
      #define MQTT_USER "mickaelcommerot1@gmail.com"
      #define MQTT_PASSWORD "ilya"
      #define MQTT_SERIAL_PUBLISH_CH "mickaelcommerot1@gmail.com/ilya"
      #define MQTT_SERIAL_ALERT "mickaelcommerot1@gmail.com/alert"
      #define MQTT_SERIAL_RECEIVER_CH "mickaelcommerot1@gmail.com/ilya"


      void reconnect();
  };

#end