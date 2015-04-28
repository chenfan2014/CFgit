class Caculator:
    def caculator(self, expression):
        self.value = eval(expression)
        return self.value

class Talker:
    def talk(self):
        print "hi, my value is %s" % self.value

class TalkingCaculator(Caculator, Talker):
    pass

tc = TalkingCaculator()
v = tc.caculator('1 + 223 * 8')
print v

tc.talk()

print hasattr(tc, 'talk')
print hasattr(tc, 'caculator')
print hasattr(tc, 'what')


print '------------------------'
print callable(getattr(tc, 'talk', None))
print callable(getattr(tc, 'caculato', None))

setattr(tc, 'goodStudy', 'Math')
print tc.goodStudy
print '=========================='
print isinstance(tc, TalkingCaculator)
print isinstance(tc, Talker)
