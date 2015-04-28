#!usr/bin/env python 
#-*- coding:utf-8 -*-
from flask import Flask, session, redirect, url_for, escape, request

app = Flask(__name__)

@app.route('/')
def index():
    if 'username' in session:
        return 'Logged in as %s ' % escape(session['username'])
    return 'You are not logged in '

@app.route('/login', methods = ['GET', 'POST'])
def login():
    if request.method == 'POST':
        session['username'] = request.form['username']
        return redirect(url_for('index'))
#下面写一个简单的功能，其中
#<input type = text name = username>这个是定义一个文本框
#<p><input type = submit value = Login>这个是定义一个按钮
    return '''
        <form action = "" method = "post">
            <p align="center">UserName<input type = text name = username></p>
            <p align="center">Password<input type = password name = password></p>
            <p align="center"><input type = submit value = LOGIN>
            <p align="center"><input type = submit value = LOGIN></p>
        <form>
    '''

#清除存储的session，这样则推出登录了
@app.route('/logout')
def logout():
    session.pop('username', None)
    return redirect(url_for('index'))

app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

if __name__ == '__main__':
    app.run()
