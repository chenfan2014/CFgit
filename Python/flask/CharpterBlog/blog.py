#!usr/bin/env python
#-*- coding:utf-8 -*-
import mysql.connector
from flask import Flask, request, session, g, redirect, url_for,abort, render_template, flash

app = Flask(__name__)
app.config.from_object(__name__)
app.config.from_envvar('FLASKR_SETTINGS', silent=True)


def connect_db():
    global conn
    conn = mysql.connector.connect(user = 'root', password = '128128', database = 'blog', use_unicode = True)
    return conn


@app.route('/')
def show_entries():    
    global cursor
    cursor = connect_db().cursor()
    cursor.execute('select * from info;')
    #return "Good job"
    entires = [dict(title=row[0], text=row[1]) for row in cursor.fetchall()]
    print entires
    return render_template('show_entires.html', entires=entires)


#we add to database, so it is POST method
@app.route('/add', methods = ['POST'])
def add_entry():
    if not session.get('logged_in'):
        abort(401)
    cursor.execute('insert into entries (id, title, text) values (?, ?, ?)', [request.form['id']], [request.form['title'], request.form['text']])
    cursor.commit()
    flash("New entry was successful posted")
    return redirect(url_for('show_entires'))

@app.route('/login', methods = ['GET', 'POST'])
def login():
    errno = None
    #send to db
    if request.method == 'POST': 
        if request.form['username'] != app.config['chenfan']:
            error = 'Invlid username'
        elif request.form['password'] != app.config['128128']:
            errno = 'Invalid password'
        else:
            session['logged_in'] = True
            flash("You were logged in")
            return redirect(url_for('show_entires'))
    return render_template('logged_in', error = error)

@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    flash ("You were logged out")
    return redirect('show_entires')
            

if __name__ == '__main__':
    app.run()
