"""mysite URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.9/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Add an import:  from blog import urls as blog_urls
    2. Import the include() function: from django.conf.urls import url, include
    3. Add a URL to urlpatterns:  url(r'^blog/', include(blog_urls))
"""
from django.conf.urls import url, include
from django.contrib import admin
from django.shortcuts import redirect
from mysite.utils import upload_image
from mysite.pages import page, menu, blog, login
from mysite.models import *
from mysite import settings


urlpatterns = [
    url(r'^admin/', admin.site.urls),

    url(r'^$',lambda r: redirect(settings.rootURL+"page/home/"), name='home'),
    url(r'^blog/', include(blog.site.urls), name='blog'),
    url(r'^auth/', include(login.site.urls), name='auth'),
    url(r'^page/', include(page.site.urls), name='page'),
    url(r'^menu/', include(menu.site.urls), name='menu'),
    url(r'^image_upload/', include(upload_image.site.urls), name='image_upload'),

]

