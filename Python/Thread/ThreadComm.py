#!usr/bin/env python
# -*- coding:utf-8 -*-
from multiprocessing import Process, Queue
import os, time, random

def write(q):
    for value in ['A', 'N', 'C']:
        print "Put %s to queue ..." % value
        q.put(value)
        time.sleep(random.random())

def read(q):
    while True:
        value = q.get(True)
        print "get %s from queue..." % value
        time.sleep(1)

if __name__ == '__main__':
    q = Queue() #父进程创建Queue
    pw = Process(target = write, args = (q,))
    pr = Process(target = read, args = (q,))

    pw.start()
    pr.start()
    time.sleep(10)
    pw.join()
    pr.terminate()
