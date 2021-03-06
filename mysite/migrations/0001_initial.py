# -*- coding: utf-8 -*-
# Generated by Django 1.9 on 2016-08-10 22:26
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Blogs',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('title', models.CharField(max_length=100)),
                ('content', models.CharField(max_length=20000)),
                ('trailer', models.BooleanField(default=False)),
                ('created', models.DateField()),
                ('last_edit', models.DateField()),
                ('views', models.IntegerField(default=0)),
                ('visible', models.BooleanField()),
                ('deleted', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='MenuItem',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('page', models.CharField(max_length=200)),
                ('label', models.CharField(max_length=300)),
                ('custom', models.BooleanField(default=False)),
                ('external', models.BooleanField(default=False)),
                ('visible', models.BooleanField()),
                ('deleted', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='Pages',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('pagename', models.CharField(max_length=50, null=True)),
                ('title', models.CharField(max_length=100)),
                ('content', models.CharField(max_length=20000)),
                ('created', models.DateField()),
                ('last_edit', models.DateField()),
                ('views', models.IntegerField(default=0)),
                ('visible', models.BooleanField()),
                ('deleted', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='Tag',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('name', models.CharField(max_length=100)),
                ('on', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='Tag1',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('name', models.CharField(max_length=100)),
                ('on', models.BooleanField(default=False)),
            ],
        ),
        migrations.AddField(
            model_name='pages',
            name='tags',
            field=models.ManyToManyField(to='mysite.Tag'),
        ),
        migrations.AddField(
            model_name='blogs',
            name='tags',
            field=models.ManyToManyField(to='mysite.Tag'),
        ),
    ]
