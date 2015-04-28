#!usr/bin/env python
#-*- coding:utf-8 -*-
import time
from _strptime import _strptime
print time.asctime()
print time.localtime()
print time.mktime(_strptime())
