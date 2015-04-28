#!usr/bin/env python
#-*- coding:utf-8 -*-
import socket
import threading
def tcplink(sock, addr):
    print "Accept new connection from %s " % addr
    sock.send("Welcome %s " % addr)
    while True:
        data = sock.recv(1024)
        if data == 'exit' or not data:
            break
        sock.send("Hello %s ! " % data)
        sock.close()
        print "Connect close"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 9090))
s.listen(5)
print "Waitting for Connecting"
while True:
    # 接受一个新连接:
    sock, addr = s.accept()
    print "sock ", sock
    print " addr ", addr
    # 创建新线程来处理TCP连接:
    t = threading.Thread(target=tcplink, args=(sock, addr, ))
    t.start()

