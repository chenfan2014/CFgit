#!usr/bin/env python
# -*- coding:utf-8 -*-
import Image, ImageFilter
im = Image.open('/home/cf/picture/gyy2.jpg')
im2 = im.filter(ImageFilter.BLUR)
im2.save('/home/cf/picture/gyy3.jpg', 'jpeg')
