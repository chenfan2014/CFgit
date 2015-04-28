#!usr/bin/env python
#-*- coding:utf-8 -*-
from flask import Flask
from flask import request
__author__ = 'cf'

app = Flask(__name__)

@app.route('/', method = ['GET', 'POST'])
def home():
    return '<h1>Home Page</h1>'

@app.route('/signin', method = ['GET'])
def signin_from():
    return '''<from action = '/signin' method = "post">
    <p><input name = "userName"></p>
    <p><input name = "Password" type = "password></p>
    <p><button type = "Submit">Sign In</button></p>
    </form>
    '''

@app.route('/signin', method = ['POST'])
def signin():
    if request.form['userName'] == 'admin' and request.form['Password'] == '128128':
        return '<h3>Welcome ! Admin </h3>'
    return '<h3>Bad userName or password</h3>'

if __name__ == '__main__':
    app.run()

