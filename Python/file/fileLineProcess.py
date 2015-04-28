#!usr/bin/env python
# -*- coding: utf-8 -*-

def process(string):
    print "Processing : " , string

f = open("test.txt")
while True:
    line = f.readline()
    if not line:
        break
    process(line)
f.close()


f = open("test.txt")
line = f.readlines()
print line , '\n'
f.close()

f = open("test.txt")
for line in f.readlines():
    process(line)
f.close()
