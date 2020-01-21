FROM ubuntu:18.04

EXPOSE 9090
WORKDIR /script/data_structure_api

RUN apt-get update && apt-get install -y apt-utils && apt-get install -y python && apt-get install -y python-pip && pip install requests && pip install flask && pip install flask_restplus && pip install paho-mqtt && pip install pymongo
#&& pip install requests

ADD script/data_structure_api .


CMD python app.py
