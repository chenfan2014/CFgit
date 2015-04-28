def stroy(**kws):
    return 'Once upon a time ,there was a %(job)s called %(name)s ' % kws

def doselfOne(name, **what):
    return name, 'Once upon a time ,there was a %(x)s called %(y)s ' % what

def power(x, y, *others):
    if others:
        print 'Received redundant parameters', others
    return pow(x, y)

def interval (start, stop = None, step = 1):
    'Imotates range() for step > 0'
    if stop is None:
        start, stop = 0, start
    result = []
    i = start
    while i < stop:
        result.append(i)
        i += step
    return result


print stroy(job = 'king', name = 'chenfan')

print doselfOne(name = "chenfan", x = 'beijing ' , y = 'shanghai')

print (1, 2, 'Get it')

print interval(10)

print interval(1, 5)
