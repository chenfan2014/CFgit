s = set([1, 2, 3, 4, 1, 2, 3, 4, 0])
a = set([7, 8, 9, 'd'])
print a.union(s)

print s | a

print a & s

print (a & s).issubset(a)


mySets = []
for i in range(10):
    mySets.append(set(range(i, i + 5)))

print reduce(set.union, mySets)
