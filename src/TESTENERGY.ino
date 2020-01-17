#include "WiFiESP.h"    
#include "Sensor.h"
#include "MQTT.h"
#include "EEPROMESP.h"

#define ID_LENGHT 40


// Definition of variables
int _len = 0;
int DataCounter=0;
Sensor::isShower = false;

//TIMER CONFIG
constexpr unsigned long DatasDelayMs = 1000;
unsigned long DatasPrev = 0;
constexpr unsigned long ShowerDelay = 60000;
unsigned long ShowerStop = 0;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(sizeof(WiFiESP::esp_id) + WIFI_CONFIG_ADDRESS);
  WiFiESP::esp_id = EEPROMESP::read_String(WIFI_CONFIG_ADDRESS);
  WiFiManager wifiManager;
  Serial.println("ESP ID after allocating");
  Serial.println(WiFiESP::esp_id.c_str());
  WiFiESP::espid = new WiFiManagerParameter("WiFiESP::espid", "Esp Id :", WiFiESP::esp_id.c_str(), ID_LENGHT);
  wifiManager.addParameter(WiFiESP::espid);
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("EEPROM BEFORE ADDING :");
  Serial.println(read_String(WIFI_CONFIG_ADDRESS));
  String idval = WiFiESP::espid->getValue();
  if (WiFiESP::esp_id != idval) {
    WiFiESP::esp_id = idval;
    EEPROMESP::writeString(WIFI_CONFIG_ADDRESS, WiFiESP::esp_id);
  }
  Serial.println("ESP ID after allocating");
  Serial.println(WiFiESP::esp_id.c_str());
  Serial.println("EEPROM AFTER ADDING :");
  Serial.println(read_String(WIFI_CONFIG_ADDRESS));
  Serial.println("connected...yeey :)");
  Serial.println("ESP_id setup:)");
  Serial.println(WiFiESP::espid->getValue());
  //////
  Sensor::attachInterrupt(14, Sensor::flow, RISING); // Setup Interrupt
  sei(); // Enable interrupts
  Sensor::_currentTime = millis();
  Sensor::_cloopTime = Sensor::_currentTime;
  ShowerStop = Sensor::_currentTime;
  //////
  Serial.setTimeout(500);// Set time out for
  MQTT::client.setServer(MQTT::mqtt_server, MQTT_PORT);
  MQTT::client.setCallback(MQTT::callback);
  WiFi.reconnect();
}
void loop() {
  MQTT::client.loop();
  auto now = millis();
  //MQTT::Datadoc["id"] = WiFiESP::espid->getValue();
  auto calcc = now - ShowerStop;
  Serial.println("now-ShowerStop::");
  Serial.println(calcc);
  Serial.println("isShower;");
  Serial.println(Sensor::isShower);
  if (now - ShowerStop > ShowerDelay) {
    Serial.println("PLUUUUUUUUUUUUUUUUUUUUS DE DOUUUUUUUUUUUUUUUUUCHE");
    Sensor::isShower = false;
  } else {
    // Sensor::isShower;=true;
  }
  if (now - DatasPrev > DatasDelayMs)
  {
    if (DataCounter < 7) {
      DatasPrev = now;
      Sensor::PrintDBTP();
      MQTT::Datadoc.clear();
      MQTT::Datadoc["temp"] = Sensor::_temperature;
      MQTT::Datadoc["debit"] = Sensor::_l_hour;
      String izi;
      serializeJson(MQTT::Datadoc, izi);
      Serial.println("MQTT::Datadoc");
      Serial.println(izi);
      MQTT::array.add(MQTT::Datadoc);
      DataCounter++;
      Serial.println("DataCounter");
      Serial.println(DataCounter);
    } else {
      DataCounter = 0;
      String Objectrep;
      String Arrayrep;
      serializeJson(MQTT::array, Arrayrep);
      Serial.println("Arrayrep");
      Serial.println(Arrayrep.c_str());
      MQTT::Objectdoc["id"] = WiFiESP::espid->getValue();
      MQTT::Objectdoc["Datas"] = MQTT::array;
      serializeJson(MQTT::Objectdoc, Objectrep);
      Serial.println("Objectrep");
      Serial.println(Objectrep.c_str());
      Serial.println("Publishing on :");
      Serial.println(MQTT_SERIAL_PUBLISH_CH);
      MQTT::client.publish(MQTT_SERIAL_PUBLISH_CH, Objectrep.c_str());
      MQTT::array = MQTT::Datasdoc.to<JsonArray>();
      MQTT::Objectdoc.clear();
    }
  }
}
