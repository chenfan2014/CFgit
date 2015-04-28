#!usr/bin/env python
#-*- coding:utf-8 -*-
import sqlite3
from flask import Flask, request, session, g, redirect, url_for, abort, render_template, flash
#from __future__ import with_statement
from contextlib import closing

'''
app.config.update((dict
    DATABASE = os.path.join(app.root_path, 'flaskrr.db'),
    DEBUG = True,
    SECRET_KEY = 'developement key',
    USERNAME = 'admin',
    PASSWORD = 'default'
    ))
'''
DATABASE = '/tmp/flaskrr.db'
DEBUG = True
SECRET_KEY = 'developement key'
USERNAME = 'admin'
PASSWORD = 'passwd'

app = Flask(__name__)
app.config.from_object(__name__)
#app.config.from_envvar('FLASKR_SETTINGS', slient = True)
app.config.from_envvar('FLASKR_SETTINGS', silent=True)
#连接数据库
def connect_db():
    return sqlite3.connect(app.config(['DATABASE']))

def init_db():
    with closing(contextlib()) as db:
        with app.open_resource('schema.sql') as f:
            db.cursor().executescript(f.read())
        db.commit()

@app.before_request
def before_request():
    g.db = connect_db()

@app.teardown_request():
    g.db.close()

@app.route('/')
def show_entries():
    cur = g.db.execute('select title, text from entires order by id desc')
    entires = [dict(title = row[0], text = row[1] for row in cur.fetchall)]
    return render_template('show_entries.html', entires = entires)



if __name__ == '__main__':
    app.run()

