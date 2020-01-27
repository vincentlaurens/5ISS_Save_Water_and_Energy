# Sensibilisation tool to save water and energy

Written by ILYA team

## Introduction

Nowadays, people are becoming increasingly concerned about the future of our planet. The consequences of climate change are worse every year. Fighting against it has become a source of inspiration for many young entrepreneurs. ILYA is a young startup that is developing two products: a cyclic shower to reduce water consumption and an awareness tool to sensitive people to save water, energy and therefore money when taking a shower. In this report, we present in detail the second product, a tool that allows measuring in real-time the water and energy consumption during a shower. The prototype we developed consists of a sensor system that collects data on the water flow and quantity, stores it in a database, and then display an analysis of this data on a web interface.  The data is captured by an autonomous and energy-efficient node and is then sent via WiFi to a local server to be stored in a database and then on the cloud. The final prototype is not fully optimized but both simple and realistic.


## TreeMap of the repository
```
Project ILYA
    |-README
    |-Documentation
    |   |-rapport.pdf
    |   |-Presentation.pdf
    |-DeviceLayer
    |   |-ESP_Code
    |-ApplicationLayer
        |-data_structure_api
        |-UI
'''



## How to deploy our services on cloud by barely method or using a host OS

In folder "services" run following command to deploy services
'''
docker-compose up -d
'''
run following command to stop all services
'''
docker-compose down
'''

Then open 127.0.0.1:1880 and on the interface
select menu on the top-right corner
In the menu select "manage palette" and in install menu
Install node-red-dashboards

Then select import menu and import two json file which are located in folder ilyaUI directory


