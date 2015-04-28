class memberCount:
    members = 0
    def init(self):
        memberCount.members += 1

one = memberCount()
one.init()
print one.members

two = memberCount()
two.init()
print two.members

class Filter:
    def init(self):
        self.blocked = []

    def filter(self, seq):
        return [x for x in seq if x not in self.blocked]

class SPAMFilter(Filter):
    def init(self):
        self.blocked = ["CHINA"]

s = SPAMFilter() 
s.init()
print s.filter(['CHINA', "CHINA", "BEIJING", "SHANGHAI"])

print s.blocked

print issubclass(SPAMFilter, Filter)

