def func(x):
    return x.isalnum()

seq = ['foo', 'beijing', '***', "Shanghai"]

print filter(func, seq)


def str(s):
    return s

what = ['china', 'guangzhou', 'shipai']

print map(str, what)

numbers = [1, 2, 3, 4]
print reduce(lambda x, y:x + y, numbers)

