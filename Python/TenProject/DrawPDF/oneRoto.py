#!usr/bin/env python
#-*- coding:utf-8 -*-
from urllib import urlopen
from reportlab.graphics.shapes import *
from reportlab.graphics.charts.lineplots import LinePlot
from reportlab.graphics.charts.textlabels import Label
from reportlab.graphics import renderPDF

URL = 'http://www.swpc.noaa.gov/ftpdir/weekly/Predict.txt'
COMMENT_CHARS = '#:'

#创建了一个画图对象
drawing = Drawing(400, 200)
data = []

#从网页中一行一行的读取
for line in urlopen(URL).readlines():
    #下面这一句判断是否为空串以及是否带有'#:'符号
    if not line.isspace() and not line[0] in COMMENT_CHARS:
        #
        data.append([float(n) for n in line.split()])

addOne = [row[5] for row in data]
pred = [row[2] for row in data] #第二列的数据作为预测值
high = [row[3] for row in data] #第三列的数据作为最高值
low = [row[4] for row in data]  #第四列的数据作为最低值
times = [row[0] + row[1]/12.0 for row in data] #第一列的数据作为横坐标的时间

lp = LinePlot()

#这里的x，y lp这个图像在我们drawing里面的起点坐标
lp.x = 50
lp.y = 50
lp.height = 125
lp.width = 300

#下面里面的zip里面的数据显示在图标上。第一个是年份，第二个是数据量
lp.data = [zip(times, pred), zip(times, high), zip(times, low), zip(times, addOne)]

lp.lines[0].strokeColor = colors.blue
lp.lines[1].strokeColor = colors.red
lp.lines[2].strokeColor = colors.green
lp.lines[3].strokeColor = colors.black

#这里就是画图，画到drawing上面去
drawing.add(lp)
drawing.add(String(250, 150, 'Sunspots', fontSize = 14, fillColor = colors.red))

renderPDF.drawToFile(drawing, 'Graph.pdf', 'SunSpots')
