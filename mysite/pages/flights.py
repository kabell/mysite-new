# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.urls import path
from django.shortcuts import render,redirect,get_object_or_404
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
            path('', self.list, name='list_flights'),
            path('new', self.new, name='new_flight'),
            path('<int:id>/edit', self.edit, name='edit_flight'),
            path('<int:id>/delete', self.delete, name='delete_flight'),

        ]
        return url_patterns

    #vypise vsetky stranky
    def list(self,request):

        flights = Flight.objects.all()
        sum_flights = sum(flight.length if flight.length else 0 for flight in flights)

        return render(request,'flights/list.html',locals())


    def new(self, request):
        if not auth(request):
            return redirect('login')

        if request.method == 'POST':
            form = FlightForm(request.POST)
            new_flight = form.save()
            return redirect('edit_flight', id=new_flight.id)

        form = FlightForm()
        return render(request, 'flights/form.html',locals())

    def edit(self, request, id):
        if not auth(request):
            return redirect('login')

        flight = get_object_or_404(Flight,id=id)
        if request.method == 'POST':
            form = FlightForm(request.POST, instance=flight)
            if form.is_valid():
                form.save()
        else:
            form = FlightForm(instance=flight)
        return render(request, 'flights/form.html',locals())

    def delete(self, request, id):
        if not auth(request):
            return redirect('login')
        flight = get_object_or_404(Flight,id=id)
        flight.delete()
        return redirect('list_flights')




site = Flights()



