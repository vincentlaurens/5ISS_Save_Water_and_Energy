/*
  Written by Ilya Team
  Content ; All Arduino libraries used by the ino main programme

*/

#ifndef WIFIESP
#define WIFIESP

  #ifndef WiFiManager_h
    #include <WiFiManager.h>
  #endif

  #ifndef ESP8266WiFi_h
    #include <ESP8266WiFi.h>
  #endif



  class WiFiESP
  {
    public:
    
      #define WIFI_CONFIG_ADDRESS 10 ;


      void reconnect();
  };

#endif