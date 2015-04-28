#!usr/bin/env python                     #  1 #  1 #  1
#-*- coding:utf-8 -*-                    #  2 #  2 #  2
import fileinput                         #  3 #  3 #  3
for line in fileinput.input(inplace = True): #  4 #  4 #  4
    line = line.rstrip()                 #  5 #  5 #  5
    num = fileinput.lineno()             #  6 #  6 #  6
    print '%-40s # %2i' % (line, num)    #  7 #  7 #  7
