#!usr/bin/env python
#-*- coding:utf-8 -*-

lst = []
for i in range(11):
    lst.append(i*i)
print lst

lst2 = [x * x for x in range(1,11)]
print lst2

print [m + n for m in "ABC" for n in "XYZ"]

l = [x * x for x in range(1, 11)]
print l

g = (x * x for x in range(10))
print g
for i in range(10):
    print g.next()

print '\n\n\n'
def Fibs(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n += 1
print Fibs(10)
    

