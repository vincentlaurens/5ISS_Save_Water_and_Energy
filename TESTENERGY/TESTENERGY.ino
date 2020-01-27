
/*
 * Includes
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include<ArduinoJson.h>
#include <math.h>
#include <WiFiManager.h>
#include<EEPROM.h>
/*
 * defines
 */
#define WIFI_CONFIG_ADDRESS 10
#define ID_LENGHT 40
#define Nobj 7
//MQTT CONFIG
//Update these with values suitable for your network.
const char* mqtt_server = "maqiatto.com";
#define mqtt_port 1883
#define MQTT_USER "mickaelcommerot1@gmail.com"
#define MQTT_PASSWORD "ilya"
#define MQTT_SERIAL_PUBLISH_CH "mickaelcommerot1@gmail.com/ilya"
#define MQTT_SERIAL_ALERT "mickaelcommerot1@gmail.com/alert"
#define MQTT_SERIAL_RECEIVER_CH "mickaelcommerot1@gmail.com/ilya"

//ESP_ID
String esp_id ;

//Shower Detection variable
bool isShower=false;

//Wifi Manager Config
WiFiClient wifiClient;
WiFiManagerParameter *espid;

//JSON COnfig
  const int capacity = JSON_OBJECT_SIZE(2);
  StaticJsonDocument<capacity> Datadoc;
  StaticJsonDocument<2048> Objectdoc;
  StaticJsonDocument<1024> Datasdoc;
  JsonArray array = Datasdoc.to<JsonArray>();

//TIMER CONFIG
//Time between 2 acquisitions
constexpr unsigned long DatasDelayMs = 10000;
unsigned long DatasPrev = 0;
//Time of a shower (will set isShower to false after 60000ms when the water flow is stopped)
constexpr unsigned long ShowerDelay = 60000;
unsigned long ShowerStop=0;

// Number of discrete sensor acquisition wanted per packet
int DataCounter=0;

PubSubClient client(wifiClient);
//
//Sensors
volatile int flow_frequency; // Measures flow sensor pulses
unsigned int l_hour; // Calculated litres/hour
float temperature;
unsigned long currentTime;
unsigned long cloopTime;
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
//
//

//EEPROM
/*
 * this function write at a specific eeprom address the Id 
 * @param : add address where to find the Id inside EEPROM
 * @param : data String object that contains the Id
 */
void writeString(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}

/*
 * This functions returns the Id stored inside the EEPROM at a given address area
 * @param : add address where to find the Id inside EEPROM
 * @return : String that contains the Id at the specific address mentionned
 */
String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}

/*
 * Function used to read data from sensors
 */
void PrintDBTP(){
  int a = analogRead(pinTempSensor);
    float R = 1023.0/a-1.0;
    R = R0*R;
    temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. Need to be calibrated!
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
   }
}
/*
 * Interrupt function which occurs when the waterflow sensors is working
 * Increase the flow frequency and set the shower detection to true.
 */
void IRAM_ATTR flow () // Interrupt function
{
   flow_frequency++;
   isShower=true;
   ShowerStop=millis();
}

/*
 * Function used to connect to the mqtt broker
 */
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish(MQTT_SERIAL_ALERT, "connected");
      // ... and resubscribe
      client.subscribe(MQTT_SERIAL_RECEIVER_CH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/*
 * Listner when a message is send to a broker , print the message.
 */
void callback(char* topic, byte *payload, unsigned int length) {
  Serial.println("-------new message from broker-----");
  Serial.print("channel:");
  Serial.println(topic);
  Serial.print("data:");
  Serial.write(payload, length);
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  EEPROM.begin(sizeof(esp_id) + WIFI_CONFIG_ADDRESS);
  esp_id=read_String(WIFI_CONFIG_ADDRESS);
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
  writeString(WIFI_CONFIG_ADDRESS,esp_id);
  }
   Serial.println("ESP ID after allocating");
  Serial.println(esp_id.c_str());
  Serial.println("EEPROM AFTER ADDING :");
  Serial.println(read_String(WIFI_CONFIG_ADDRESS));
  Serial.println("connected...yeey :)");
  Serial.println("ESP_id setup:)");
  Serial.println(espid->getValue());
  //////
     attachInterrupt(14, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
   ShowerStop= currentTime;
  //////
  Serial.setTimeout(500);// Set time out for
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();
;
}

/*
 * Function usefull to publish serial data
 * we do not use it in the code but it is here just in case
 */
void publishSerialData(char *serialData) {
  if (!client.connected()) {
    reconnect();
  }
  client.publish(MQTT_SERIAL_PUBLISH_CH, serialData);
}

/*
 * Main function of the projet the loop
 */
void loop() {
  client.loop();
  auto now=millis();
  auto calcc=now-ShowerStop;
  if(calcc>ShowerDelay){
  isShower=false;
  }
  if(now-DatasPrev>DatasDelayMs)
  {
    if(DataCounter<Nobj){
      DatasPrev=now;
      PrintDBTP();
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
