# -*- coding: utf-8 -*-
# Generated by Django 1.10.3 on 2016-12-04 21:32
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('mysite', '0006_auto_20161204_1723'),
    ]

    operations = [
        migrations.AlterField(
            model_name='blogs',
            name='content',
            field=models.CharField(max_length=200000),
        ),
    ]