#!usr/bin/env python
# -*- coding:utf-8 -*-
import time, threading, random

def loop():
    print "Thread %s is running " % threading.current_thread().name
    n = 0
    while n < 5:
        n += 1
        time.sleep(random.random())
        print "Thread %s >>> %s " % (threading.current_thread().name, n)

    print "Thread %s is ended" % threading.current_thread().name

if __name__ == '__main__':
    print "Thread %s is running ...." % threading.current_thread().name
    t = threading.Thread(target = loop)
    t.start()
    t.join()
    print "Ended %s " % threading.current_thread().name
