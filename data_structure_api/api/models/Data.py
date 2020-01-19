from flask_restplus import Resource, Api, fields, abort, Api, reqparse, marshal
from collections import OrderedDict
from api.restplus import api_app
import random
import string

hotelData = api_app.model('hotelInfos', {
    "hotel name": fields.String(description='Enter the hotel name', required=True, example="Fayrouz"),
    "hotel building": fields.String(description='Enter the name or the number of the building', required=True,example="23"),
    "room number": fields.String(description='Enter the number of the room', default="", example="205", required=True),
    "id": fields.String(description='Enter the room id,is the device id need to be unique for each hotel', required=True, default="", example=""),
})

hotelIDs = api_app.model('updareData', {
    "Old_id": fields.String(description='Enter the room old id', required=True, default="", example=""),
    "New_id": fields.String(description='Enter the new id of the room  ', required=True, default="", example=""),

})

User = api_app.model('addUser', {
    "hotel": fields.String(description='Enter the hotel name', required=True, default="", example=""),
    "username": fields.String(description='Enter the username ', required=True, default="", example=""),
    "password": fields.String(description='Enter the password  ', required=True, default="", example=""),


})