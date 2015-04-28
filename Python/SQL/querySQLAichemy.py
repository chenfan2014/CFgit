#!usr/bin/env python
#-*- coding:utf-8 -*-
from sqlalchemy import create_engine, Column, String
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()
class User(Base):
    __tablename__ = 'test'

    id = Column(String(20), primary_key = True)
    name = Column(String(20))

conn = create_engine('mysql+mysqlconnector://root:128128@localhost:3306/chenfan')

DBSession = sessionmaker(bind = conn)

sess = DBSession()
user = sess.query(User).filter(User.id=='001').one()
print 'Type : ', type(user)
print "Name : ", user.name
sess.close()
