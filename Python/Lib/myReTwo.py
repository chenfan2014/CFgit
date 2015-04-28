import re
m = re.match(r'^(\d{3})\-(\d{3,8})$', '120-321313')
if m:
    print "You match right"
else:
    print "Match wrong"

print "ALL Number is : ", m.group(0)
print "Area Code : " , m.group(1)
print "Number : ", m.group(2)

print 'q,fd,,,fd'.split(',')
print re.split(r'\,+', 'a,n,,,,,fda,f')
