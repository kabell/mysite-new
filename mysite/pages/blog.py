# -*- coding: utf-8 -*-
from django.shortcuts import render,redirect,get_object_or_404
from mysite.pages.common import Common
from mysite.models import Blogs, Tag
from mysite.forms import BlogEditForm
from mysite.utils.authorise import auth
from django.urls import path





class Blog(Common):
    def __init__(self):
        Common.__init__(self)


    @property
    def urls(self):
        return self.get_urls()

    def get_urls(self):

        url_patterns = [
            path('', self.list, name='blog_list'),
            path('new/', self.new, name='blog_new'),
            path('<int:id>/', self.show, name='blog_show'),
            path('<int:id>/edit', self.edit, name='blog_edit'),
            path('<int:id>/delete', self.delete, name='blog_delete'),
        ]

        return url_patterns
    @property
    def get_sidebar_items(self):
        return self.sidebar_items()

    def sidebar_items(self):
        return Blogs.objects.all()[5:]

    #vypise vsetky stranky
    def list(self,request):

        visible = [True]
        if auth(request):
            visible.append(False)

        blogposts = Blogs.objects.all().filter(deleted=False,visible__in=visible).distinct().order_by('-id')

        return render(request,'blog/list.html',locals())

    def new(self,request):
        if not auth(request):
            return redirect('login')

        if request.method == 'POST':
            form = BlogEditForm(request.POST)
            new_blog = form.save()
            return redirect('blog_show', id=new_blog.id)

        form = BlogEditForm()
        return render(request, 'blog/form.html',locals())

    def edit(self,request, id):
        if not auth(request):
            return redirect('login')

        blog = get_object_or_404(Blogs,id=id)
        if request.method == 'POST':
            form = BlogEditForm(request.POST, instance=blog)
            if form.is_valid():
                form.save()
                return redirect('blog_show',id=id)

        else:
            form = BlogEditForm(instance=blog)

        return render(request, 'blog/form.html',locals())

    def delete(self,request,id):
        if not auth(request):
            return redirect('login')

        blog = get_object_or_404(Blogs,id=id)
        if blog:
            blog.deleted = True
            blog.save()
        return redirect('blog_list')


    def show(self,request,id):
        if not auth(request):
            post = get_object_or_404(Blogs,id=id, visible=True)
        else:
            post = get_object_or_404(Blogs,id=id)

        #zakomentovane koli velkej casovej narocnosti
        post.views+=1
        post.save()

        return render(request, 'blog/post.html',locals())


site = Blog()
