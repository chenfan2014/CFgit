#! /bin/src/env python
# -*- coding : utf-8 -*-
names = ["beijng", "shanghai", "guangzhou", "shenzhen"]
for name in names:
    print name

sumRes = 0
for x in range(101):
    sumRes = sumRes + x
print sumRes

print range(10)


num = int(raw_input())
if num < 100:
    print "good"
else:
    print "wrong"
