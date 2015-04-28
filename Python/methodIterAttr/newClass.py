#!usr/bin/env python
#-*- coding:utf-8 -*-
__metaclass__ = type

class Bird:
    def __init__(self):
        self.hungry = True

    def eat(self):
        if self.hungry:
            print "Aaaaah. eat so much"
            self.hungry = False
        else:
            print "Thank you"

class SongBird(Bird):
    def __init__(self):
        super(SongBird, self).__init__()    #here is the super function
        self.sound = 'Swquak'
    def sing(self):
        print "Sing to begin : " + self.sound

