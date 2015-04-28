class Fibs:
    def __init__(self):
        self.count = 0
        self.lhs = 0
        self.rhs = 1

    def __iter__(self):
        return self

    def next(self):
        if self.count < 100:
            self.lhs, self.rhs = self.rhs, self.lhs + self.rhs
            self.count += 1
            return self.lhs
        raise StopIteration

fibs = Fibs()
print list(fibs)
