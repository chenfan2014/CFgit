#!/usr/bin/env python
# -*- coding:utf-8 -*-
from string import Template
s = Template('$x, good $y')
s.substitute(x = 'Chenfan', y = 'job')
