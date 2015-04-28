#!usr/bin/env python
# -*- coding:utf-8 -*-
from urllib import urlopen
import re
text = urlopen('http://www.swpc.noaa.gov/ftpdir/weekly/Predict.txt').read()
fwrite = open('data.txt', 'w')
fwrite.write(text)
fwrite.close()

data = []
count = 0
fread = open('data.txt', 'r')
f = open('last.txt', 'w')
#这里用re表达式把所有的非数据去掉了
while True:
    line = fread.readline()
    m = re.match(r'20*', line)
    if m:
        f.write(line)
    if not line:
        break
fread.close()
