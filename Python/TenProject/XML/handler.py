#!usr/bin/env python
#-*- coding:utf-8 -*-
from xml.sax.handler import ContentHandler
from xml.sax import parse

#创建一个TestHandler类继承ContentHandler，进行解析
class TestHandler(ContentHandler):

    in_headline = False
    def __init__(self, headlines):
        ContentHandler.__init__(self)
        self.headlines = headlines
        self.data = []

    def startElement(self, name, attrs):
        if name == 'h1':
            self.in_headline = True

    def endElement(self, name):
        if name == 'h1':
            text = ''.join(self.data)
            self.data = []
            self.headlines.append(text)
            self.in_headline = False

    def characters(self, string):
        if self.in_headline:
            self.data.append(string)

headlines = []

#调用parse函数进行解析，然后在通过TestHandler函数进行实际解析
parse('website.xml', TestHandler(headlines))

print 'The following <h1> element were found :'
for h in headlines:
    print h
