#!usr/bin/env python
#-*- coding:utf-8 -*-
from sqlalchemy import Column, String, create_engine
from sqlalchemy.orm import sessionmaker
#from sqlalchemy.ext.declarative import daclarative_base
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class User(Base):
    __tablename__ = "test"

    id = Column(String(20), primary_key = True)
    name = Column(String(20))

engineConn = create_engine('mysql+mysqlconnector://root:128128@localhost:3306/chenfan')
#'数据库类型+数据库驱动名称://用户名:口令@机器地址:端口号/数据库名'
DBSession = sessionmaker(bind = engineConn)
session = DBSession()

newUser = User(id = '001', name = 'Chenfan')
session.add(newUser)
session.commit()
session.close()
