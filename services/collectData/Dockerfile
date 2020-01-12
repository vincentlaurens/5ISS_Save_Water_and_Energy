FROM ubuntu:18.04

EXPOSE 9090
WORKDIR /script

RUN apt-get update && apt-get install -y python3 && apt-get install -y python3-pip

#Put code python for collect here
ADD script/test.py .


CMD python3 test.py
