#!usr/bin/env python
# -*- coding:utf-8 -*-
from email.mime.text import MIMEText
from email import encoders
from email.header import Header
from email.utils import parseaddr, formataddr
import smtplib

def _format_addr(s):
    name, addr = parseaddr(s)
    return formataddr((\
        Header(name, 'utf-8').encode(),\
        addr.encode('utf-8') if isinstance(addr,unicode)  else addr))


# 输入Email地址和口令:

from_addr = raw_input('From: ')
password = raw_input('Password: ')
# 输入SMTP服务器地址:
smtp_server = raw_input('SMTP server: ')
# 输入收件人地址:
to_addr = raw_input('To: ')

msg = MIMEText("Hello, send by python ubuntu", 'plain', 'utf-8')

msg['From'] = _format_addr(u'Python Chenfan % s' % from_addr)
msg['To'] = _format_addr(u'Admin %s' % to_addr)
msg['Subject'] = Header(u'By CF', 'utf-8').encode()



server = smtplib.SMTP(smtp_server, 25) # SMTP协议默认端口是25
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()
