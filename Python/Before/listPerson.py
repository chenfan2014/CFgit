#!/usr/bin/env python
# -*- coding: utf-8 -*-
person = ['chenfan', 19, "Boy"]
print "Len of person is : ", len(person)
print person[-1]    
#-1的意思是我们获取list的倒数第一个元素，也就是最后一个元素。如果是-2则是倒数第二个元素
print person[-2]
print person
person.append("Pingpong")
print person

person.insert(1, "What")    #我们在位置1插入what
print person

person.pop(-2)              #我们删除倒数第二个元素
print person

person[1] = "Do"            #我们把位置1的元素置换称Do  
print person


