#!usr/bin/env python
#-*- coding:utf-8 -*-
import itertools
natuals = itertools.count(1)
ns = itertools.takewhile(lambda x: x <= 10, natuals)
print '_____________________________'
for n in ns:
    print n
