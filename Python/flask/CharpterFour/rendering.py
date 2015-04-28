#!usr/bin/env python
#-*- coding:utf-8 -*-
from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello world'

@app.route('/hello')
def hello_china():
    return 'Hello china'

@app.route('/hello/<name>')
def hello(name = None):
    return render_template('hello.html', name = name)

if __name__ == '__main__':
    app.run()
