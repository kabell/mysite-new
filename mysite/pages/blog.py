# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.shortcuts import render,redirect
from mysite.pages.common import Common
from mysite.models import Blogs, Tag
from mysite.forms import BlogEditForm
from mysite.utils.authorise import auth




class Blog(Common):
    def __init__(self):
        Common.__init__(self)


    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            url(r'^$', self.list, name='blog_list'),
            url(r'^new/$', self.blog_new, name='blog_new'),
            url(r'^(\w+)/$', self.show, name='blog_show'),
            url(r'^(\w+)/edit/$', self.edit, name='blog_edit'),
            url(r'^(\w+)/delete/$', self.delete, name='blog_delete'),
        ]

        return url_patterns
    @property
    def get_sidebar_items(self):
        return self.sidebar_items()

    def sidebar_items(self):
        return Blogs.objects.all()[5:]

    #vypise vsetky stranky
    def list(self,request):
        tags = Tag.objects.all()

        if 'tags' not in request.session:
            request.session['tags']={'4':True}

        if 'filter' in request.POST:
            for tag in tags:
                if str('tag'+str(tag.id)) in request.POST:
                    request.session['tags'][str(tag.id)]=True
                elif request.session['tags'].get(str(tag.id),None)!=None:
                    del request.session['tags'][str(tag.id)]

        tags_on = []
        for t in tags:
            if request.session['tags'].get(str(t.id),None):
                t.on = True
                tags_on.append(t)

        visible = [True]
        if auth(request):
            visible.append(False)

        if tags_on == []:
            blogposts = Blogs.objects.all().filter(deleted=False,visible__in=visible).distinct().order_by('-id')
        else:
            blogposts = Blogs.objects.all().filter(deleted=False,visible__in=visible,tags__in=tags_on).distinct().order_by('-id')
        request.session['lama']='Kabell'

        return render(request,'blog/list.html',locals())

    def blog_new(self,request):
        if not auth(request):
            return redirect('login')

        form = BlogEditForm({'visible':True,'id':0})
        tags = Tag.objects.all()


        return render(request, 'blog/form.html',locals())

    def edit(self,request,blogid):
        if not auth(request):
            return redirect('login')

        #ak prisla poziadavka na update, tak updatneme
        if request.method == 'POST':
            form = BlogEditForm(request.POST)
            if form.is_valid():
                try:
                    obj = Blogs.objects.get(id=request.POST.get('id',0))
                    obj.populate(request.POST,False)

                except (Blogs.DoesNotExist, ValueError):
                    obj = Blogs()
                    obj.populate(request.POST)

                obj.save()
                #update tags
                tags = Tag.objects.all()
                obj.tags = []

                for tag in tags:
                    if 'tag'+str(tag.id) in request.POST:
                        obj.tags.add(tag)
                obj.save()
            return self.show(request,obj.id)

        post = self.get(blogid)
        form = BlogEditForm(post.__dict__)

        tags = Tag.objects.all()
        my_tags = post.tags.all()
        for tag in tags:
            for my_tag in my_tags:
                if tag.id == my_tag.id:
                    tag.on = True

        return render(request, 'blog/form.html',locals())

    def delete(self,request,blogid):
        if not auth(request):
            return redirect('login')

        blog = self.get(blogid)
        if blog:
            blog.deleted = True
            blog.save()
        return self.list(request)


    def show(self,request,blogid):
        post = self.get(blogid)


        #zakomentovane koli velkej casovej narocnosti
        post.views+=1
        post.save()

        return render(request, 'blog/post.html',locals())

    def get(self,blogid):
        try:
            post = Blogs.objects.get(id=blogid)
        except Blogs.DoesNotExist:
            return None
        return post

site = Blog()