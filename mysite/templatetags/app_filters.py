from django.template.defaulttags import register
import re
from mysite.models import Blogs, MenuItem
import locale

locale.setlocale(locale.LC_ALL, 'sk_SK.UTF-8')

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

@register.filter()
def currency(value):
    if not value:
        return ""
    value = str(value).replace(',','.')
    return locale.currency(float(value), grouping=True).replace(' ', '&nbsp;')

@register.filter
def to_human_time(val):
    return str(int(val/60))+"h "+str(val%60)+"m"
###############
