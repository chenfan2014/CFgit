#!usr/bin/env python
#-*- coding:utf-8 -*-
import Image
im = Image.open('/home/cf/picture/gyy.jpg')
width, height = im.size
print width, height
im.thumbnail((width//2, height//2))
im.save('/home/cf/picture/gyy2.jpg')
