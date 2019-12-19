#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include<ArduinoJson.h>
#include <math.h>


// Update these with values suitable for your network.
 char ssid[] = "MgMk";
const char* password = "grosboule";
const char* mqtt_server = "maqiatto.com";
#define mqtt_port 1883
#define MQTT_USER "mickaelcommerot1@gmail.com"
#define MQTT_PASSWORD "ilya"
#define MQTT_SERIAL_PUBLISH_CH "mickaelcommerot1@gmail.com/ilya"
#define MQTT_SERIAL_ALERT "mickaelcommerot1@gmail.com/alert"
#define MQTT_SERIAL_RECEIVER_CH "mickaelcommerot1@gmail.com/ilya"

WiFiClient wifiClient;

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
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      //Serial.print("temperature = ");
   // Serial.println(temperature);
    //  Serial.print(l_hour,DEC); // Print litres/hour
    //  Serial.println(" L/hour");
   }
}

void IRAM_ATTR flow () // Interrupt function
{
   flow_frequency++;
}

void setup_wifi() {
  //delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.persistent(false);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

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

void callback(char* topic, byte *payload, unsigned int length) {
  Serial.println("-------new message from broker-----");
  Serial.print("channel:");
  Serial.println(topic);
  Serial.print("data:");
  Serial.write(payload, length);
  Serial.println();
}

wifiSetup (){
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();
  
}

void setup() {
  Serial.begin(9600);
  //////
     attachInterrupt(14, flow, RISING); // Setup Interrupt
     attachInterrupt(14, wifiSetup, RISING);
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
  //////
  Serial.setTimeout(500);// Set time out for
}

void publishSerialData(char *serialData) {
  if (!client.connected()) {
    reconnect();
  }
  client.publish(MQTT_SERIAL_PUBLISH_CH, serialData);
}
void loop() {
  client.loop();
  PrintDBTP();
  const int capacity = JSON_OBJECT_SIZE(3);
  StaticJsonDocument<capacity> doc;
  doc["id"] = 1234;
  doc["temp"] = temperature;
  doc["debit"] = l_hour;
  String rep;
  serializeJson(doc,rep);
  client.publish(MQTT_SERIAL_PUBLISH_CH, rep.c_str());

  /*client.publish(MQTT_SERIAL_PUBLISH_CH, "hello");*/
 /* if (Serial.available() > 0) {
     char mun[501];
     memset(mun,0, 501);
     Serial.readBytesUntil( '\n',mun,500);
     publishSerialData(mun);
    }*/
    delay(1000);
}
