def flatten(arr):
    for i in arr:
        for j in i:
            yield j

a = [[1, 2, 3], [4, 6], [8]]
print list(flatten(a))



def flat(arr):
    try:
        for i in arr:
            for j in flat(i):
                yield j
    except TypeError:
        yield arr

b = [[1, [2, [4, 5, 6] , [3], ]]]   
print list(flat(b))
