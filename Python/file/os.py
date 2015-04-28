#!usr/bin/env python
#-*- coding:utf-8 -*-
import os
import string

for file in os.listdir(os.getcwd()):
    print file

if os.name == 'posix':
    command = "dir"
else:
    print os.name
    command = "ls -la"
#os.system(command)

program = "python"
arguments = ['fileIter.py']
print os.execvp(program, (program,)  + tuple(arguments))
print "Gpdd"


