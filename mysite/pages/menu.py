# -*- coding: utf-8 -*-
from django.shortcuts import render,redirect
from django.conf.urls import url

from mysite.models import MenuItem
from mysite.forms import MenuItemForm
from mysite.pages.common import Common
from mysite.utils.authorise import auth


class Menu(Common):

    def __init__(self):
        Common.__init__(self)

    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [

            url(r'^$', self.menu_show, name='menu_show'),
            url(r'^new/', self.menu_new, name='menuitem_new'),
            url(r'^(\d+)/delete/$', self.menu_delete, name='menuitem_delete'),
            url(r'^(\d+)/edit/$', self.menuitem_edit, name='menuitem_edit'),
            url(r'^(\d+)/up/$', self.menuitem_up, name='menuitem_up'),
            url(r'^(\d+)/down/$', self.menuitem_down, name='menuitem_down'),
        ]

        return url_patterns

    def menuitem_up(self,request,id):
        if not auth(request):
            return redirect('login')
        obj = MenuItem.objects.get(id=id)
        obj1 = MenuItem.objects.filter(id__lt=id).order_by('-id')[0]
        obj.id,obj1.id = obj1.id,obj.id
        obj.save()
        obj1.save()
        return self.menu_show(request)

    def menuitem_down(self,request,id):
        if not auth(request):
            return redirect('login')
        obj = MenuItem.objects.get(id=id)
        obj1 = MenuItem.objects.filter(id__gt=id).order_by('id')[0]
        obj.id,obj1.id = obj1.id,obj.id
        obj.save()
        obj1.save()
        return self.menu_show(request)



    def menu_new(self,request):
        if not auth(request):
            return redirect('login')
        form = MenuItemForm({'id':0,'visible':True})
        return render(request, 'menu/menuitem.html',locals())

    def menu_delete(self,request,id):
        if not auth(request):
            return redirect('login')
        try:
            MenuItem.objects.get(id=id).delete()
        except MenuItem.DoesNotExist:
            pass
        self.sidebar_menu = MenuItem.objects.all().filter(visible=True)

        return self.menu_show(request)

    def menuitem_edit(self, request, id):
        if not auth(request):
            return redirect('login')

        if request.method == 'POST':
            form = MenuItemForm(request.POST)
            print('prisla poziadavka')
            if form.is_valid():
                try:
                    obj = MenuItem.objects.get(id=request.POST.get('id',-1))
                except (MenuItem.DoesNotExist, ValueError):
                    obj = MenuItem()

                obj.populate(request.POST)
                obj.save()
                #po zmeneni menu ho treba znova nacitat
                self.sidebar_menu = MenuItem.objects.all().filter(visible=True)
            else:
                print('form isnt valid')
            x= self.menu_show(request)
            print(x)
            return x


        try:
            obj = MenuItem.objects.get(id=id)
            form = MenuItemForm(obj.__dict__)
        except MenuItem.DoesNotExist:
            form = MenuItemForm()

        return render(request, 'menu/menuitem.html',locals())


    def menu_show(self,request):
        if not auth(request):
            return redirect('login')
        items = MenuItem.objects.all()

        return render(request, 'menu/show.html',locals())

    def menu_edit(self,request):
        pass


site = Menu()





