#!usr/bin/env python
# -*- coding : utf-8 -*-
def process(string):
    print "processing : ", string

f = open("test.txt")
char = f.read(1)
while char:
    process(char)
    char = f.read(1)
f.close()

f = open("test.txt")
while True:
    char= f.read(1)
    if not char:
        break
    #process(char)
    print char

f.close()
