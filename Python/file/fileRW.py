#! usr/bin/env python
# -*- coding:utf-8 -*-
f = open("two.txt", 'w')
f.write("Beijing City\n")
f.write("Shanghai City\n")
f.write("guangzhou\n")
f.close()

lines = list(open("two.txt"))
print lines
f.close()

print "Begin three value"
f = open("two.txt")
first, second, third = open("two.txt")
print first, second, third
f.close()
