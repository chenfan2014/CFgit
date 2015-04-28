#!usr/bin/env python
# -*- encoding: utf-8 -*-
class Person:
    def setName(self, name):
        self.name = name

    def getName(self):
        return self.name

    def greet(self):
        print "hello , i am %s " % self.name

class Class:
    def method(self):
        print 'I have a self'

def function():
    print "In function"

class Secretive:
    def __inaccessible(self):       #这里在函数名字前面加了下划线表示private
        print "can not used by outsize"
    def accessible(self):
        print "can use by outside"
        

one = Person()
one.setName("chenfan")
s = one.getName()
print s
one.greet()

two = Person()
two.setName("Beijing")
two.setName("shanghai")
print two.getName()

print two.name

three = Class()
three.method()
three.method = function
three.method()
three.method()

print '--------------------------------------------'
four = Secretive()
four.accessible()
four._Secretive__inaccessible()     #要访问私有成员函数，那么则使在函数前面加上类名_Secretive
