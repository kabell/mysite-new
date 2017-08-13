from django.template.defaulttags import register
import re
from mysite.models import Blogs, MenuItem

@register.filter
def get_item(dictionary, key):
    return dictionary.get(key, None)
@register.filter
def get_all(obj):
    return obj.all()
@register.filter
def remove_html(obj):
    return re.sub("<.*?>", " ", obj)
@register.filter
def get_login(obj):
    return obj.session.get('login',False)
@register.filter
def get_sidebar_menu(obj):
    return MenuItem.objects.all().filter(visible=True)
@register.filter
def get_sidebar_blog(obj):
    return Blogs.objects.all().filter(deleted=False,visible=True).order_by('-id')[:5]

###############
