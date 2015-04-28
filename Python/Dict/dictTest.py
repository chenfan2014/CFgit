#!/usr/bin/env python
# -*- coding:utf-8 -*-
from copy import deepcopy
d = {}
d['name'] = "Chenfan"
d['age'] = 23
print d

returned_value = d.clear()
print d
print returned_value

dic = {'name':['chenfan'], 'age':19, 'city':'guangzhou'}
dicOne = dic.copy()     #浅拷贝
dicTwo = deepcopy(dic)   #深拷贝
dic['grade'] = 'good'
dic['name'].append('lilin')
print dic               #Output:
print dicOne            #Output:
print dicTwo            #Output:

