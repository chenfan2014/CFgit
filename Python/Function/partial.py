import functools

'''
def int2(x, base = 2):
    return int(x,base)
'''

int3 = functools.partial(int, base = 10)
int2 = functools.partial(int, base = 2)
print int2('1000')
print int3('1000')
