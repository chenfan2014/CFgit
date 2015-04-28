#!usr/bin/env python
# -*- coding:utf-8 -*-

from multiprocessing import Process
import os
def runPro(name):
    print "Run child process %s, id is %s " % (name, os.getpid())

if __name__ == '__main__':
    print "Parend process (%s)" % os.getpid()
    p = Process(target = runPro, args = ('test', ))
    print 'Process will start'
    p.start()
    p.join()
    print "Process end"
