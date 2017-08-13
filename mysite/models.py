# -*- coding: utf-8 -*-
from django.db import models
import datetime


class MenuItem(models.Model):
    id = models.AutoField(primary_key=True)
    page = models.CharField(max_length=200)
    label = models.CharField(max_length=300)
    custom = models.BooleanField(default=False)
    external = models.BooleanField(default=False)
    visible = models.BooleanField()

    deleted = models.BooleanField(default=False)


    def __str__(self):
        return self.label

    def populate(self,d):
        self.page = d.get('page', '')
        self.label = d.get('label', '')
        self.visible = d.get('visible', False)
        self.deleted = d.get('deleted', False)
        self.custom = d.get('custom', False)
        self.external = d.get('external', False)








class Tag(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    on = models.BooleanField(default=False)

    def __str__(self):
        return str(self.id)+self.name+str(self.on)




class Pages(models.Model):
    id = models.AutoField(primary_key=True)
    pagename = models.CharField(max_length=50, null=True)
    title = models.CharField(max_length=100)
    content = models.CharField(max_length=200000)
    created = models.DateField()
    last_edit = models.DateField()
    tags = models.ManyToManyField(Tag)
    views = models.IntegerField(default=0)
    visible = models.BooleanField()
    deleted = models.BooleanField(default=False)

    def __str__(self):
        return self.pagename

    def populate(self,d):
        self.pagename = d.get('pagename', '')
        self.title = d.get('title', '')
        self.content = d.get('content', '')
        self.created = d.get('created', datetime.datetime.now())
        self.last_edit = d.get('last_edit', datetime.datetime.now())
        #self.tags = d.get('tags', '')
        self.visible = d.get('visible', False)
        self.deleted = d.get('deleted', False)


class Blogs(models.Model):
    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=100)
    title_img = models.CharField(max_length=200,default='')
    content = models.CharField(max_length=200000)
    trailer = models.BooleanField(default=False)
    created = models.DateField()
    last_edit = models.DateField()
    tags = models.ManyToManyField(Tag)
    views = models.IntegerField(default=0)
    visible = models.BooleanField()
    deleted = models.BooleanField(default=False)

    def __str__(self):
        return str(self.id)

    def populate(self,d,new=True):
        self.title = d.get('title', '')
        self.title_img = d.get('title_img', '')

        self.content = d.get('content', '')
        if new:
            self.created = d.get('created', datetime.datetime.now())
        self.last_edit = d.get('last_edit', datetime.datetime.now())
        self.trailer = d.get('trailer', False)
        self.visible = d.get('visible', False)
        self.deleted = d.get('deleted', False)