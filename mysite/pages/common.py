# -*- coding: utf-8 -*-
from mysite.models import MenuItem
import mysite.settings
from mysite.models import Blogs

class Common:

    def __init__(self):

        self.rootURL = mysite.settings.rootURL
        self.sidebar_blog = Blogs.objects.all().filter(deleted=False,visible=True).order_by('-id')[:5]
