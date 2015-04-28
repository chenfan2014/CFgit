#!usr/bin/env python
#-*- coding:utf-8 -*-
import base64
print base64.b64encode('China Guangzhou SCNU')
print base64.b64decode('Q2hpbmEgR3Vhbmd6aG91IFNDTlU=')
print base64.b64encode('i\xb7\x1d\xfb\xef\xff')
print base64.urlsafe_b64encode('i\xb7\x1d\xfb\xef\xff')
print base64.urlsafe_b64decode('abcd--__++__')
