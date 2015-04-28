def func():
    print "Before this"
    
@func
def count():
    print "In this"
#count = func(count)
count(2, 3)
