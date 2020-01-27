from flask import Flask, json, Blueprint
from flask_restplus import Resource, Api, fields, abort, Api
from collections import OrderedDict 
import ConfigParser
from api.restplus import api_app
from api.endpoint.Controller import ns as db 
import logging
from api.Services.db  import connect_broker
import threading
import time
import requests
from datetime import datetime



config = ConfigParser.ConfigParser()
config.read("config.conf")


app = Flask(__name__)
app.config.SWAGGER_UI_JSONEDITOR = True
app.app_context().__enter__()

blueprint = Blueprint('api', __name__, url_prefix='/'+config.get("end_points", "root"))
api_app.init_app(blueprint)
api_app.add_namespace(db)
app.register_blueprint(blueprint)
logging.basicConfig(level=logging.DEBUG)
@app.before_first_request
def activate_job():
    def run_job():
        print("je me connecte")
        connect_broker()
        print("je me connecte")
    thread = threading.Thread(target=run_job)
    thread.start()

def start_runner():
    def start_loop():
        not_started = True
        while not_started:  
            try:         
                if config.get("host", "ip") !="0.0.0.0":
                     r = requests.get('http://'+config.get("host", "ip")+':'+config.get("host", "port")+'/api/')
                else:
                     r = requests.get('http://localhost:'+(config.get("host", "port")+'/api/'))
                print('http://'+config.get("host", "ip")+':'+config.get("host", "port")+'/api/')
                if r.status_code == 200 :
                    print('Server started, quiting start_loop')
                    not_started = False
                print(r.status_code)
            except:
                print('Server not yet started')
            time.sleep(2)
           
    thread = threading.Thread(target=start_loop)
    thread.start()  

if __name__ == '__main__':
    start_runner()
    app.run(debug=True, host=config.get("host", "ip"), port=int(config.get("host", "port")))