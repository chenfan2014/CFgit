#!usr/bin/env python 
# -*- coding : utf-8 -*-
from multiprocessing import Pool
import os, time, random

def longTimeTask(name):
    print "Run task %s , id is %s" % (name, os.getpid())
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print "Task %s run %0.2f seconds" % (name, (end - start))

if __name__ == '__main__':
    print "Parent process %s : " % os.getpid()
    p = Pool()
    for i in range(9):
        p.apply_async(longTimeTask, args = (i, ))
    print "Waitting for all subprocesses done"
    p.close()
    p.join()
    print "ALL Done"
