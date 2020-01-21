FROM ubuntu:18.04

EXPOSE 9090
WORKDIR /script

RUN apt-get update && apt-get install -y python && apt-get install -y python-pip && pip install flask && pip install flask_rest


ADD script/data_structure_api .


CMD python3 app.py
