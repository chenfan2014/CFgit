#!usr/bin/env python 
# -*- coding : utf-8 -*-
number = input("Input a number : ")
if number<= 10 and number >= 1:
    print "Right"
else:
    print "Wrong"

name = ""
while not name or name.isspace():
    name = raw_input("Please input your name : ")
print "Hello, %s !" % name

words = ['one', 'two', 'three', 'four', 'five']
for word in words:
    print word

print range(5)
print "\n"
print range(1, 3)

for number in range(2, 10):
    print number
