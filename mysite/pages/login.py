# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.shortcuts import render
from mysite.pages.common import Common
from django.shortcuts import redirect
from mysite.forms import LoginForm
from mysite import settings


class Login(Common):
    def __init__(self):
        Common.__init__(self)

    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            url(r'^login/$', self.login_page, name='login'),
            url(r'^logout/$', self.logout, name='logout'),

        ]

        return url_patterns

    def login_page(self,request):
        if request.method == 'POST':
            form = LoginForm(request.POST)
            if form.is_valid():
                result = self.login(request,request.POST['login'],request.POST['password'])
                if result:
                    return redirect(settings.rootURL+"page/home/")
        form = LoginForm({'login':request.POST.get('login','')})
        return render(request, 'login/form.html',locals())


    def login(self,request,username, password):
        if username == 'kabell' and password == 'lamalama':
            request.session['login'] = username
            return True
        return False

    def logout(self,request):
        if 'login' in request.session:
            del request.session['login']
        return self.login_page(request)


site = Login()