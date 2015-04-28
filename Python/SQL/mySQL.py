#!usr/bin/env python 
# -*- coding:utf-8 -*-
import mysql.connector
conn = mysql.connector.connect(user = 'root', password = '128128', database = 'test', use_unicode = True)
cursor = conn.cursor()
cursor.execute('create table user (id varchar(20) primary key, name varchar(20)')
cursor.exectue('insert into user (id, name) values (%s， %s)', ['1', 'chenfan'])

print cursor.rowcount
conn.commit()
cursor.close()

cursor = conn.cursor()
cursor.exectue('select * from user where id = %s', '1')
values = cursor.fetchall()
print values
cursor.close()
conn.close()

