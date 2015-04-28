#!usr/bin/env python
# -*- coding:utf-8 -*-
import copy
print dir(copy), '\n'
print [n for n in dir(copy) if not n.startswith('_')] #打印所有不是下划线开始的那些文件
print '\n\n'
print [n for n in dir(copy) if not n.endswith('_')]

print copy.__all__
