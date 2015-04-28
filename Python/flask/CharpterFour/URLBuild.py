#!usr/bin/env python
#-*- coding:utf-8 -*-
from flask import Flask, url_for
app = Flask(__name__)

@app.route('/')
def index():
    return "Good job"

@app.route('/login')
def login():
    pass

@app.route('/user/<username>')
def profile(username):
    pass

if __name__ == '__main__':
    with app.test_request_context():
        print url_for('login')
    app.run()
