#!usr/bin/env python
#-*- coding:utf-8 -*-
from flask import request

@app.route('/login', method=['POST', 'GET'])
def login():
    errno = None
    if request.method == 'POST':
        if valid_login(request.form['username'],
                        request.form['password']):
            return login_the_user_in(request.form['username'])
        else:
            error = 'Invaild username/password'
    return render_template('login.html', error = error)

@app.route('/uplode', method = ['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        f = request.files['the_File']
        f.save('var/www/uploads/uploads.txt')
        #from werkzeug import secure_filename
        #f.save('/var/www/uploads' + secure_filename(f.filename))
        #这里导入secure_filename使得我们可以知道我们存储文件的原来的名字

#reading cookies
@app.route('/')
def index():
    username = request.cookies.get('username')

#storing cookies
from flask import make_response
@app.route('/')
def index():
    resp = make_response(render_template(...))
    resp.set_cookie('username', 'the username')
    return resp

from flask import abort, redirect, url_for

#重定向
@app.route('/')
def index():
    return redirect(url_for('login'))

#出错处理
@app.route('/login')
def login():
    abort(40)
    thisIsNeverExecuted()

#自定义error处理
from flask import render_template

@app.errorhandller(404)
def pageNotFound(error):
    return render_template('page_not_found.html'), 404

@app.errorhandller(404)
def not_found(error):
    resp = make_response(render_template('error.html', 404))
    resp.headers['something'] = 'A value'
    return resp
