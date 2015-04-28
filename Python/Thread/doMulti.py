#!usr/bin/env python
#-*- coding:utf-8 -*-
import os
import Muiti
print "Parent process %s " % os.getpid()
p = Muiti.Process(target = Muiti.runPro, args = ('test', ))
print "Process will start"
p.start()
p.join()
print "Process end"
