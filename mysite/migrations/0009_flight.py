# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2018-01-19 20:25
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('mysite', '0008_blogs_title_img'),
    ]

    operations = [
        migrations.CreateModel(
            name='Flight',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('z', models.CharField(max_length=3, null=True)),
                ('do', models.CharField(max_length=3, null=True)),
                ('date', models.DateField(null=True)),
                ('start', models.TimeField(null=True)),
                ('end', models.TimeField(null=True)),
                ('length', models.IntegerField(null=True)),
                ('company', models.CharField(max_length=50, null=True)),
                ('flight_no', models.CharField(max_length=20, null=True)),
                ('seat', models.CharField(max_length=5, null=True)),
                ('pos', models.CharField(max_length=10, null=True)),
                ('aircraft', models.CharField(max_length=20, null=True)),
                ('booking_code', models.CharField(max_length=30, null=True)),
                ('price', models.FloatField(null=True)),
                ('comment', models.CharField(max_length=300, null=True)),
            ],
        ),
    ]
