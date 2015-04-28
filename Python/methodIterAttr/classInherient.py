__meta = type
class Countlist(list):
    def __init__(self, *arg):
        super(Countlist, self).__init__(*arg)
        self.count = 0
    def __getitem__(self, index):
        self.count += 1
        return super(Countlist, self).__getitem__(index)

c1 = Countlist(range(20))
print c1

print c1[3]

print c1.count

print c1[2] + c1[1]

print c1.count

