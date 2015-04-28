#!usr/bin/env python
# -*- coding:utf-8 -*-

"""
这个解析器会在每一个块开始的时候匹配一个start函数
然后使用合适的函数名作为参数调用HTMLRenderer的函数进行处理

"""
class Handler:
    def callback(self, prefix, name, *arg):
        method = getattr(self, prefix + name, None)
        if callable(method):
            return method(*arg)

    def start(self, name):
        self.callback('start_', name)

    def end(self, name):
        self.callback('end_', name)

    def sub(self, name):
        def substitution(match):
            result = self.callback('sub_', name, match)
            if result is None:
                result = match.group(0)
            return result
        return substitution

'''
通过超类处理程序start(), end(), sub进行调用
'''
class HTMLRenderer(Handler):
    def start_document(self):
        print '<html><head><title>....</title></head><body>'

    def end_document(self):
        print '<body></html>'

    def start_paragraph(self):
        print '<p>'

    def end_paragrah(self):
        print '</p>'

    def start_title(self):
        print '<h1>'

    def end_title(self):
        print '</h1>'

    def start_heading(self):
        print '<h2>'

    def end_heading(self):
        print '</h2>'

    def start_list(self):
        print '<ul>'

    def end_list(self):
        print '</ul>'

    def start_listItem(self):
        print '<li>'

    def end_listItem(self):
        print '</li>'

    def sub_emphasis(self, match):
        return '<em>%s</em>' % match.group(0)

    def sub_url(self, match):
        return '<a href = %s>%s</a>' % match.group(1), match.group(1)

    def sub_email(self, match):
        return '<a href = %s>%s</a>' % match.group(1), match.group(1)

    def feed(self, data):
        print data
