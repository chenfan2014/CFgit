#!/usr/bin/env python
#encoding=utf-8
import jieba

seg_list = jieba.cut("CHina is good", cut_all = True)
print("Full mode : " + "/ ".join(seg_list))  #全模式
