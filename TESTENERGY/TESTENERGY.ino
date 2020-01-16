#include "WiFi.h"    //Library which contains all constants and global variables or define variables
#include "Sensor.h" 
#include "Energy.h"
#include "EEPROM_ESP.h" // Libraries which contains all Arduino Libraries

//TIMER CONFIG 
 
constexpr unsigned long DatasDelayMs = 1000; 
unsigned long DatasPrev = 0; 
constexpr unsigned long ShowerDelay = 60000; 
unsigned long ShowerStop=0; 

void setup() {
  Serial.begin(9600);
  EEPROM.begin(sizeof(esp_id) + WIFI_CONFIG_ADDRESS);
  esp_id= EEPROM_ESP.read_String(WIFI_CONFIG_ADDRESS);
  WiFiManager wifiManager;
  Serial.println("ESP ID after allocating");
  Serial.println(esp_id.c_str());
  espid=new WiFiManagerParameter("EspId", "Esp Id :", esp_id.c_str(), ID_LENGHT);
  wifiManager.addParameter(espid);
  wifiManager.autoConnect("AutoConnectAP"); 
  Serial.println("EEPROM BEFORE ADDING :");
  Serial.println(read_String(WIFI_CONFIG_ADDRESS));
  String idval=espid->getValue();
  if (esp_id!=idval){
  esp_id=idval;
  EEPROM_ESP.writeString(WIFI_CONFIG_ADDRESS,esp_id);
  }
   Serial.println("ESP ID after allocating");
  Serial.println(esp_id.c_str());
  Serial.println("EEPROM AFTER ADDING :");
  Serial.println(read_String(WIFI_CONFIG_ADDRESS));
  Serial.println("connected...yeey :)");
  Serial.println("ESP_id setup:)");
  Serial.println(espid->getValue());
  //////
     Sensor.attachInterrupt(14, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
   ShowerStop= currentTime;
  //////
  Serial.setTimeout(500);// Set time out for
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  WiFi.reconnect();
;
}
void loop() {
  client.loop();
  auto now=millis();
  //Datadoc["id"] = espid->getValue();
   auto calcc=now-ShowerStop;
   Serial.println("now-ShowerStop::");
   Serial.println(calcc);
    Serial.println("IsShower");
    Serial.println(isShower);
  if(now-ShowerStop>ShowerDelay){
    Serial.println("PLUUUUUUUUUUUUUUUUUUUUS DE DOUUUUUUUUUUUUUUUUUCHE");
  isShower=false;
  }else{
    // isShower=true;
  }
  if(now-DatasPrev>DatasDelayMs)
  {
    if(DataCounter<7){
      DatasPrev=now;
      Sensor.PrintDBTP();
      Datadoc.clear();
      Datadoc["temp"] = temperature;
      Datadoc["debit"] = l_hour;  
      String izi;
      serializeJson(Datadoc,izi);
      Serial.println("Datadoc");
      Serial.println(izi);
      array.add(Datadoc);
      DataCounter++;
       Serial.println("DataCounter");
      Serial.println(DataCounter);
    }else{
      DataCounter=0;    
      String Objectrep;
      String Arrayrep;
      serializeJson(array,Arrayrep); 
       Serial.println("Arrayrep");
      Serial.println(Arrayrep.c_str()); 
      Objectdoc["id"]=espid->getValue();
      Objectdoc["Datas"]=array;
      serializeJson(Objectdoc,Objectrep);  
      Serial.println("Objectrep");
      Serial.println(Objectrep.c_str());
      Serial.println("Publishing on :");
      Serial.println(MQTT_SERIAL_PUBLISH_CH);
      client.publish(MQTT_SERIAL_PUBLISH_CH, Objectrep.c_str()); 
      array=Datasdoc.to<JsonArray>();
      Objectdoc.clear();
    }   
  }
}
