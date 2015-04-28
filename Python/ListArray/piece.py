#!/usr/bin/env python 
# -*- coding : utf-8 -*-
numbers = [1, 2, 3, 4, 5]

numOne = numbers[1:4]
print "Number One is : " + str(numOne)

numTwo = numbers[:]
print "Number Two is : " + str(numTwo)

numThree = numbers[-4:-1]
print "Number Three is : " + str(numThree)

name = raw_input("Please input your name : ")
print "Name was Piece to " + name[:4]

print "Name differ : " + name[::2]

print numbers[::-1]
