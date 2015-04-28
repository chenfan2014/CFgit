class Foobar:
    def __init__(self, value = 42):
        print value
        self.someVar = value


foo = Foobar()
print foo.someVar
poo = Foobar('what a pity')
print poo.someVar
