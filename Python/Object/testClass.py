class Student(object):
    def getScore(self):
        return self._score

    def setScore(self, value):
        if not isinstance(value, int):
            raise ValueError("Not integer")
        if value < 0 or value > 100:
            raise ValueError("score must betweem 0-100")
        self._score = value

s = Student()
s.setScore(70)
print s.getScore()
