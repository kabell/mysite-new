# -*- coding: utf-8 -*-
from django import forms


class MenuItemForm(forms.Form):
    id = forms.IntegerField(widget=forms.HiddenInput(), required=False)
    page = forms.CharField(max_length=200,required=False,label='Odkazovaná stránka',widget=forms.TextInput(attrs={'class':'form-control'}))
    label = forms.CharField(max_length=300,required=False,label='Názov zobrazený v menu',widget=forms.TextInput(attrs={'class':'form-control'}))
    visible = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Viditeľné')
    custom = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Vlastný odkaz')
    external = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Odkaz mimo stránku')



class PageEditForm(forms.Form):
    id = forms.IntegerField(widget=forms.HiddenInput(), required=False)
    pagename = forms.CharField(max_length=50,required=False,label='Názov stránky(len alfanum)',widget=forms.TextInput(attrs={'class':'form-control'}))
    title = forms.CharField(max_length=100,required=False,label='Nadpis',widget=forms.TextInput(attrs={'class':'form-control'}))
    content = forms.CharField(max_length=200000,label='Obsah',widget=forms.Textarea(attrs={'class':'ckeditor','name':'ckeditor'}),required=False)
    visible = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Viditeľná')

class BlogEditForm(forms.Form):
    id = forms.IntegerField(widget=forms.HiddenInput(), required=False)
    title = forms.CharField(max_length=100,required=True,label='Nadpis',widget=forms.TextInput(attrs={'class':'form-control'}))
    title_img = forms.CharField(max_length=200,required=False,label='Title obrazok',widget=forms.TextInput(attrs={'class':'form-control'}))
    content = forms.CharField(max_length=200000,label='Obsah',widget=forms.Textarea(attrs={'class':'ckeditor','name':'ckeditor'}),required=False)
    visible = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Viditeľný')
    trailer = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Trailer')


class ImageUploadForm(forms.Form):
    popisok = forms.CharField(max_length=300,label='Popisok')
    image = forms.FileField(widget=forms.FileInput(attrs={'id':'imgInp'}))

class LoginForm(forms.Form):
    login = forms.CharField(max_length=20,widget=forms.TextInput(attrs={'class':'form-control'}),label='Login',required=False)
    password = forms.CharField(widget=forms.PasswordInput(attrs={'class':'form-control'}),label='Password',required=False)

class FlightForm(forms.Form):
    z = forms.CharField(max_length=3,required=False)
    do = forms.CharField(max_length=3,required=False)
    date = forms.DateField(required=False, widget=forms.SelectDateWidget())
    start = forms.TimeField(required=False)
    end = forms.TimeField(required=False)
    length = forms.IntegerField(required=False)
    company = forms.CharField(max_length=50,required=False)
    flight_no = forms.CharField(max_length=20,required=False)
    seat = forms.CharField(max_length=5,required=False)
    pos = forms.CharField(max_length=10,required=False)
    aircraft = forms.CharField(max_length=20,required=False)
    booking_code = forms.CharField(max_length=30,required=False)
    price = forms.FloatField(required=False)
    comment = forms.CharField(max_length=300,required=False)






