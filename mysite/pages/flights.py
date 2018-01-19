# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.shortcuts import render,redirect
from django.http import HttpResponse
from mysite.pages.common import Common
from mysite.models import Flight
from mysite.forms import FlightForm
from mysite.utils.authorise import auth

import datetime





class Flights(Common):

    def __init__(self):
        Common.__init__(self)

    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            url(r'^$', self.list, name='list_flights'),
        ]

        return url_patterns

    #vypise vsetky stranky
    def list(self,request):

        flights = Flight.objects.all()

        return render(request,'flights/list.html',locals())





site = Flights()



