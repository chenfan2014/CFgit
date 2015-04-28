#!usr/bin/env python
#-*- coding:utf-8 -*-
import threading, time, random
balance = 0
lock = threading.Lock()
def changeMoney(n):
    time.sleep(random.random())
    global balance
    balance += n
    print "Account : " , balance
    balance -= n
    print "Account : " , balance


def runThread(n):
    for i in range(10000):
        lock.acquire()
        try:
            changeMoney(n)
        finally:
            lock.release()

t1 = threading.Thread(target = changeMoney, args = (5, ))
t2 = threading.Thread(target = changeMoney, args = (8, ))
t1.start()
t2.start()
time.sleep(3)
t1.join()
t2.join()
print "Account Money total : " , balance
