#!usr/bin/env python
# -*- coding:utf-8 -*-
#这个函数用来处理每一个语句使得后面都加上\m
def fread(file):
    for line in file:
        yield line
    yield '\n'

#这个函数在这利主要是把所有的字符串六安接称一个字符串。
def blocks(file):
    block = [] #定义一个存放字符串的列表
    for line in fread(file):
        if line.strip():            #去除字符串两边的空格
            block.append(line)
        elif block:
            yield ''.join(block).strip()  #用空格链接所有的字符串
            block = []
