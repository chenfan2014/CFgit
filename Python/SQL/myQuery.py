#!usr/bin/env python
#-*- coding:utf-8
import mysql.connector

conn = mysql.connector.connect(user = 'root', password = '128128', database = 'chenfan', use_unicode = True)

curr= conn.cursor()
curr.execute('select * from user where id = 1')
val = curr.fetchall()
print val
curr.close()
conn.close()
