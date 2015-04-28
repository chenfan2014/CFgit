#!usr/bin/env python
# -*- coding : utf-8 -*-
__meta__=type   
def repeater(value):
    while True:
        new = (yield value)
        if new is not None:
            value = new

r = repeater(32)
print r.next()

print r.send("Hello world")
