#!usr/bin/env python
# -*- coding: utf-8 -*-
f = open("test.txt")
for line in f:
    print line
f.close()

for line in open("test.txt"):
    print line

import sys
for line in sys.stdin:
    print line
