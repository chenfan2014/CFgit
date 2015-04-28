#!usr/bin/env python
#-*- coding : utf-8 -*-

import urllib2

url = 'http://www.baidu.com/'
response = None
try:
    response = urllib2.urlopen(url,timeout=5)
except urllib2.URLError as e:
    if hasattr(e, 'code'):
        print 'Error code:',e.code
    elif hasattr(e, 'reason'):
        print 'Reason:',e.reason
finally:
    if response:
        response.close()
