fibs = [0, 1]
for i in range(8):
    fibs.append(fibs[-2] + fibs[-1])
    print "fibs[", i + 2, '] = ', fibs[i + 2]
print fibs
