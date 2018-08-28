# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.shortcuts import render
from mysite.forms import ImageUploadForm
import random, datetime ,PIL
from PIL import Image
import mysite.settings
import os

class Upload:

    def __init__(self):
        self.path = 'static/upload/'
        self.rootURL = mysite.settings.rootURL


    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            url(r'^$', self.upload, name='image_upload'),
        ]
        return url_patterns

    def upload(self,request):
        print('som tu')
        if request.method == 'POST':
            print('post')
            form = ImageUploadForm(request.POST, request.FILES)
            if form.is_valid():
                filename = self.handle_uploaded_file(request.FILES['image'])
                popisok = request.POST.get('popisok',"")
            else:
                print('invalid_form')

        form = ImageUploadForm()

        return render(request,'upload_image/form.html',locals())

    def handle_uploaded_file(self,f):
        now = datetime.datetime.now()
        filename = self.path+'image_'+str(now.year)+"-"+str(now.month)+"-"+str(now.day)+"_"+str(now.hour)+"-"+str(now.minute)+"-"+str(now.second)+""
        fullpath = mysite.settings.BASE_DIR + "/"+ filename
        with open(fullpath, 'wb+') as destination:
            for chunk in f.chunks():
                destination.write(chunk)
        self.resample(fullpath)
        return filename

    def resample(self,filename):
        basewidth = 1800
        img = Image.open(filename)
        wpercent = (basewidth / float(img.size[0]))
        hsize = int((float(img.size[1]) * float(wpercent)))
        img = img.resize((basewidth, hsize), PIL.Image.ANTIALIAS)
        img.save(filename+'.jpg')
        os.remove(filename)

site = Upload()



