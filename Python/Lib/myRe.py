import re
text = 'The China is a big country ' 
m = re.match('.', text)
if m:
    print repr(".*"), "=>", repr(m.group(0))

m = re.match(".*", text)
if m:
    print repr(".*"), "=>", repr(m.group(0))

m = re.match("\w+", text)
if m:
    print repr("\w+"), "=>", repr(m.group(0))

m = re.match("\d+", text)
if m:
    print repr("\d+"), "=>", repr(m.group(0))

print re.match('q', 'quit')
print re.match('q', 'uit')

text = "10/15/99"
print '\n\n\n',text, '\n\n\n'
text = "Example 3: There is 1 date 10/25/95 in here!"
m = re.search("(\d{1,2})/(\d{1,2})/(\d{2,4})", text)
print m.group(1), m.group(2), m.group(3)
month, day, year = m.group(1, 2, 3)
print month, day, year
date = m.group(0)
print date, '\n\n\n\n'

test = 'Beijing is the capacity of China'
print re.sub("fun", "entertaining", text)

print re.sub("[^\w]+", "-", text)

print re.sub("\S+", "-BEEP-", text)

