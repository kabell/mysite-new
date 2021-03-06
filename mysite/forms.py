# -*- coding: utf-8 -*-
from django import forms
from mysite.models import Flight, Blogs



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

class BlogEditForm(forms.ModelForm):
    id = forms.IntegerField(widget=forms.HiddenInput(), required=False)
    title = forms.CharField(max_length=100,required=True,label='Nadpis',widget=forms.TextInput(attrs={'class':'form-control'}))
    title_img = forms.CharField(max_length=200,required=False,label='Title obrazok',widget=forms.TextInput(attrs={'class':'form-control'}))
    content = forms.CharField(max_length=200000,label='Obsah',widget=forms.Textarea(attrs={'class':'ckeditor','name':'ckeditor'}),required=False)
    visible = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Viditeľný')
    trailer = forms.BooleanField(widget=forms.CheckboxInput(),required=False,label='Trailer')

    class Meta:
        model = Blogs
        fields = ['title', 'title_img', 'content', 'visible', 'trailer']


class ImageUploadForm(forms.Form):
    popisok = forms.CharField(max_length=300,label='Popisok')
    image = forms.FileField(widget=forms.FileInput(attrs={'id':'imgInp'}))

class LoginForm(forms.Form):
    login = forms.CharField(max_length=20,widget=forms.TextInput(attrs={'class':'form-control'}),label='Login',required=False)
    password = forms.CharField(widget=forms.PasswordInput(attrs={'class':'form-control'}),label='Password',required=False)

class FlightForm(forms.ModelForm):
    class Meta:
        model = Flight
        fields = ['z', 'do', 'date', 'start', 'end', 'length', 'company', 'flight_no', 'seat', 'pos',
                  'aircraft', 'booking_code', 'price', 'comment']






