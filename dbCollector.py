import paho.mqtt.client as mqtt #import the client
from pymongo import MongoClient 
import json 
# Function to process recieved message

def process_message(client, userdata, message):  
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)
    connect_mongo(json.loads(str(message.payload.decode("utf-8"))))


def connect_mongo(data):
    conn = MongoClient('192.168.43.61', 27017)
    conn = MongoClient()
    db = conn.ilya
    collection = db.ilyaSensors
    informations = { 
       "Sensor_id":data["id"],
        "Temp":data["temp"],
        "Debit":data["debit"],
        } 
    rec_id1 = collection.insert_one(informations) 
    cursor = collection.find() 
   
# Create client
client = mqtt.Client(client_id="hamzoz") 
# Assign callback function
client.on_message = process_message
# Connect to broker
client.username_pw_set("mickaelcommerot1@gmail.com","ilya")
client.connect("maqiatto.com", 1883, 60)
# Subscriber to topic
client.subscribe("mickaelcommerot1@gmail.com/ilya", qos=2)
# Run loop
client.loop_forever()
