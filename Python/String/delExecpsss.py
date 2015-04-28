#!usr/bin/env python
# -*- coding: utf-8 -*-
x = ['hello', 'world']
y = x
y[1] = 'china'
print x
del x
print y
del y[1]
print y

exec 'print "Hello world"'

from math import sqrt
scope = {}
exec "sqrt = 1" in scope    #这句话的意思是sqrt的作用范围是sqrt里面
print sqrt(4)               #这里是非sqrt里面，所以这里不会执行exec里面的

scope['sqrt']

res = eval(raw_input("Please input a  count function : "))
print res

scopeTwo = {}
scopeTwo['x'] = 'beijing '
scopeTwo['y'] = 'shanghai'
ress = eval('x, y', scopeTwo)
print ress
