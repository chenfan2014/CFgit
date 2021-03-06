#!usr/bin/env python
from flask import Flask
app = Flask(__name__)
@app.route('/')
def hello_world():
    return 'Hello world'

@app.route('/second')
def second():
    return 'Second page'

@app.route('/user/<username>')
def show_user_profile(username):
    return 'User %s ' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
    return "Post %d " % post_id


if __name__ == '__main__':
    app.run(debug = True)
