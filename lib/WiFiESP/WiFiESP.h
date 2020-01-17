/*
  Written by Ilya Team
  Content ; All WiFiESP class libraries for manage wifi used by the ino main programme

*/

#ifndef WIFIESP
#define WIFIESP

  #ifndef Arduino_h
    #include <Arduino.h>
  #endif
  #ifndef WiFiManager_h
    #include <WiFiManager.h>
  #endif

  #ifndef ESP8266WiFi_h
    #include <ESP8266WiFi.h>
  #endif

  //definitions
  #define WIFI_CONFIG_ADDRESS 10



  class WiFiESP
  {
    public:
    WiFiManagerParameter *espid;
    String esp_id;
  };

#endif