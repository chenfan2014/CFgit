#!usr/bin/env python
#-*- coding:utf-8 -*-
from collections import deque
q = deque(['d', 'a', 'z', 'h'])
print q
q.append('y')
print q
q.appendleft('b')
print q
