#!usr/bin/env python
# -*- coding:utf-8 -*-
def func(x):
    return x*x

def add(x, y):
    return x + y

f = map(func, [1, 2, 3, 5, 6, 7])
print f

a = reduce(add, [1, 3, 5, 7, 9])
print a

def funct(x, y):
    return x * 10 + y

def char2num(s):
    return {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, \
            '6':6, '7':7, '8':8, '9':9}[s]

num = reduce(funct, map(char2num, '1234456'))
print num

def lazySum(*args):
    def Sum():
        ax = 0
        for n in args:
            ax += n
        return ax
    return Sum

f = lazySum(1, 2, 3, 4, 5)
print f
print f()
