#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

char hotel_n[40];
char room_n[6] ;
char stage_n[4] ;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    WiFiManagerParameter hotel("hotel", "Hotel Name :", hotel_n, 40);
    wifiManager.addParameter(&hotel);
    WiFiManagerParameter stage("etage", "Stage Number:", stage_n, 4);
    wifiManager.addParameter(&stage);
    WiFiManagerParameter room("chambre", "Room Number :", room_n, 6);
    wifiManager.addParameter(&room);
    //reset saved settings
    //wifiManager.resetSettings();
    
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
    Serial.println(hotel_n);
    Serial.println(stage_n);
    Serial.println(room_n);
    
}

void loop() {
    // put your main code here, to run repeatedly:
    
}
