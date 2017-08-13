from django.contrib import admin
from mysite.models import MenuItem, Tag, Pages, Blogs

admin.site.register(MenuItem)
admin.site.register(Blogs)
admin.site.register(Tag)
admin.site.register(Pages)