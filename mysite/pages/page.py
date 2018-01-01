# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.shortcuts import render,redirect
from django.http import HttpResponse
from mysite.pages.common import Common
from mysite.models import Pages
from mysite.forms import PageEditForm
from mysite.utils.authorise import auth

import datetime





class Page(Common):

    def __init__(self):
        Common.__init__(self)

    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            url(r'^$', self.list, name='page_list'),
            url(r'^new/$', self.page_new, name='page_new'),
            url(r'^([\w\-]+)/$', self.show, name='page'),
            url(r'^([\w\-]+)/edit/$', self.edit, name='page_edit'),
            url(r'^([\w\-]+)/delete/$', self.delete, name='page_delete'),


        ]

        return url_patterns

    def get(self,pagename):
        print('lama')
        try:
            page = Pages.objects.get(pagename=pagename)
        except Pages.DoesNotExist:
            try:
                page = Pages.objects.get(id=int(pagename))
            except (Pages.DoesNotExist,ValueError):
                return Pages.objects.get(pagename='404')
        return page



    def page_new(self,request):
        if not auth(request):
            return redirect('login')
        form = PageEditForm({'id':0,'visible':True})
        return render(request, 'page/form.html',locals())

    def edit(self,request,pagename):
        if not auth(request):
            return redirect('login')

        #ak prisla poziadavka na update, tak updatneme
        if request.method == 'POST':
            form = PageEditForm(request.POST)
            if form.is_valid():
                try:
                    obj = Pages.objects.get(id=request.POST.get('id',-1))
                except (Pages.DoesNotExist, ValueError):
                    obj = Pages()

                obj.populate(request.POST)
                obj.save()
            return self.show(request,pagename)


        page = self.get(pagename)
        form = PageEditForm(page.__dict__)
        return render(request, 'page/form.html',locals())

    def delete(self,request,pagename):
        if not auth(request):
            return redirect('login')

        page = self.get(pagename)
        if page:
            page.deleted = True
            page.save()
        return self.list(request)


    def show(self,request,pagename='home'):
        page = self.get(pagename)
        only_body = request.GET.get('only_body',False)
        #zakomentovane koli velkej casovej narocnosti
        #page.views+=1
        #page.save()

        return render(request, 'page.html',locals())

    #vypise vsetky stranky
    def list(self,request):
        if not auth(request):
            return redirect('login')
        pages = Pages.objects.all()

        return render(request,'page/list.html',locals())

site = Page()



