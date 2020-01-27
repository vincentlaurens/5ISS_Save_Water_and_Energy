import paho.mqtt.client as mqtt #import the client
from pymongo import MongoClient 
import json 
import pymongo
import time
from datetime import datetime
# Function to process recieved message

def process_message(client, userdata, message):  
    print("je suis la")
    insert_Sensor_data(json.loads(str(message.payload.decode("utf-8"))))


def connect_broker():
    
    # Create client
    client = mqtt.Client(client_id="b") 
    # Assign callback function
    client.on_message = process_message
    # Connect to broker
    client.username_pw_set("mickaelcommerot1@gmail.com","ilya")
    client.connect("maqiatto.com", 1883, 60)
    # Subscriber to topic
    client.subscribe("mickaelcommerot1@gmail.com/ilya", qos=0)
    # Run loop
    client.loop_forever()



def create_hotel_db(hotel_name,dprt_name,room_num,id):
    conn = MongoClient('localhost', 27017)
    dblist = conn.list_database_names()
    db = conn["indexes"]
    collection=db[hotel_name]
    info={ "_id": id, "path": hotel_name+"/"+dprt_name+"/"+room_num }
    try:
        ids=collection.insert_one(info)
        conn.close()
    except pymongo.errors.DuplicateKeyError:
         print("le id existe deja merci de le modifier")

           
def insert_data(data):
    path = { "_id": data["id"] }
    conn = MongoClient('localhost', 27017)
    db = conn["indexes"]
    for name in db.collection_names():
        if db[name].find_one(path) is None: 
            pass
        else:
                url=db[name].find_one(path)["path"].split("/")
                info={ "_id": data["id"], "room": url[2]}
                db = conn[url[0]]
                try:
                    dpt= db[url[1]]
                    dpt.insert_one(info)
                except pymongo.errors.DuplicateKeyError:
                    continue 
                room=db["room_"+url[2]]
                room.insert_one({"data":data["string"]})
                break

def update(old_id,id):
    path = { "_id": old_id }
    conn = MongoClient('localhost', 27017)
    db = conn["indexes"]
    for name in db.collection_names():
        if db[name].find_one(path) is None: 
            pass
        else:
                url=db[name].find_one(path)
                url["_id"]=id
                db[name].insert_one(url)
                db[name].delete_one(path) 
                print url["path"]
                url=url["path"].split("/")
                db = conn[url[0]]
                try:
                    if db[url[1]].find_one(path) is not None: 
                        dpt=db[url[1]].find_one(path)
                        dpt["_id"]=id
                        db[url[1]].insert_one(dpt)
                        db[url[1]].delete_one(path)
                except pymongo.errors.DuplicateKeyError:
                     continue 
                break
def get_hotels_room():
    conn = MongoClient('localhost', 27017)
    db = conn["indexes"]
    return db.collection_names()

def insert_Sensor_data(data):
    ts=time.time()
    data_dict = data
    datas=data["Datas"]
    path = { "_id": str(data["id"]) }
    print("after")
    conn = MongoClient('localhost', 27017)
    print("ok")
    db = conn["indexes"]
    print("ok")
    step=1
    for name in db.collection_names():
        if db[name].find_one(path) is None: 
            print("None")
        else:
                url=db[name].find_one(path)["path"].split("/")
                info={ "_id": data_dict["id"], "room": url[2]}
                db = conn[url[0]]
                try:
                    dpt= db[url[1]]
                    dpt.insert_one(info)
                except pymongo.errors.DuplicateKeyError:
                    print("prob") 
                print(url)
                room=db["room_"+str(url[2])]
                structure_data=[]
                step=1
                print("je rentre")
                for i in reversed(datas):
                   print(i)
                   tmp={}
                   if ( i !=None):
                     tmp=i
                   else:
                       continue 
                   if ( None in tmp.viewvalues() and tmp == None):
                       print("None here")
                   else:
                        tmp["timestamp"]=ts-10*step
                   structure_data.append(tmp)
                   step=step+1
                print(structure_data)
                room.insert_many(structure_data)
                conn.close()
                break

def get_hotel():
    conn = MongoClient('localhost', 27017)
    db = conn["indexes"]
    cursor=db.collection_names()
    rooms=[]
    for name in cursor :
        docs=db[name].find({},{"_id":0})
        for doc in docs:
           rooms.append(doc["path"].replace("/", " "))
    return sorted(rooms)

def get_Data(data):
    infos=data.split(" ")
    conn = MongoClient('localhost', 27017)
    db = conn[infos[0]]
    rooms=[]
    docs=db["room_"+infos[2]].find({},{"_id":0})
    for doc  in docs:
        rooms.append(doc)
    print(json.dumps(rooms))
    return rooms

def create_User(hotel_name,username,password):
    conn = MongoClient('localhost', 27017)
    dblist = conn.list_database_names()
    db = conn["Users"]
    collection=db[hotel_name]
    info={ "_id": username, "password":password }
    try:
        ids=collection.insert_one(info)
        conn.close()
    except pymongo.errors.DuplicateKeyError:
         print("username existe deja merci de le modifier")


def verifie(hotel_name,username,password):
    conn = MongoClient('localhost', 27017)
    dblist = conn.list_database_names()
    db = conn["Users"]
    collection=db[hotel_name]
    info={"_id": username}
    
    if collection.find_one(info)["password"]==password :
          return True
    else:
        return False

def get_hotel(name):
    conn = MongoClient('localhost', 27017)
    db = conn["indexes"]
    rooms=[]
    docs=db[name].find({},{"_id":0})
    for doc in docs:
        rooms.append(doc["path"].replace("/", " "))
    return sorted(rooms)


#connect_broker()