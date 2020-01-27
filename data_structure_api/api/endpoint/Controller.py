from __future__ import print_function
from flask import Flask, json, request
from flask_restplus import Resource, api, fields, abort, api, reqparse, marshal_with
from collections import OrderedDict
from ..restplus import api_app
from ..models.Data import *
from ..Services.db import * 


ns = api_app.namespace('DBOPERATION', version='1.0',title="DATA STORING CONTROLLER ",description='DATA STRUCTURE api_app TO STORE AND RETREIVE DATA ')


@ns.route('/Hotel')
@ns.response(404, 'NO AGENT DEPLOYED')
@ns.response(500, 'COMMUNICATION PROBLEME')
class get_all_agents (Resource):
    def get(self):
        """GET all hotels"""
        return get_hotel()

    @api_app.expect(hotelData)    
    def post(self):
        """Add room id  """
        create_hotel_db(request.json["hotel name"],request.json["hotel building"],request.json["room number"],request.json["id"])

    @api_app.expect(hotelIDs)    
    def put(self):
        """update room hotel id """
        update(request.json["Old_id"],request.json["New_id"])

@ns.route('/Data')
@ns.response(404, 'NO AGENT DEPLOYED')
@ns.response(500, 'COMMUNICATION PROBLEME')
class get_all_agents (Resource):
    def post(self):
        """Add room id  """
        return get_Data(request.json["hotel name"]+" "+request.json["hotel building"]+" "+request.json["room number"])


@ns.route('/User')
@ns.response(404, 'NO AGENT DEPLOYED')
@ns.response(500, 'COMMUNICATION PROBLEME')
class get_all_agents (Resource):
    def post(self):
        """Add user id  """
        print(request)
        return create_User(request.json["hotel name"],request.json["USERNAME"],request.json["password"])

@ns.route('/verify')
@ns.response(404, 'NO AGENT DEPLOYED')
@ns.response(500, 'COMMUNICATION PROBLEME')
class get_all_agents (Resource):
    def post(self):
        """Add user id  """
        print(request)
        return verifie(request.json["hotel"],request.json["username"],request.json["password"])

@ns.route('/Hotel/<string:name>')
@ns.response(404, 'NO AGENT DEPLOYED')
@ns.response(500, 'COMMUNICATION PROBLEME')
class get_all_agents (Resource):
    def get(self,name):
        """GET all hotels"""
        return get_hotel(name)


