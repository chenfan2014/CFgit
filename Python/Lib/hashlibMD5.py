#!usr/bin/env python 
#-*- coding:utf-8 -*-
import hashlib
md5 = hashlib.md5()
md5.update("Chenfan in the SCNU")
print md5.hexdigest()
md = hashlib.md5()
md.update("Chenfan in the SCN")
print md.hexdigest()
