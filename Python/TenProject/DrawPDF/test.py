import re
f = open("last.txt", 'r')
count = 0
buf = []
line = ' '
for num in f:
    for i in num:
        if re.match('[a-zA-Z0-9]+', i):
            line = int(line)*10 + int(i)
        else:
            print line
    count += 1
    if count == 1:
        break

print "Result is ", line
