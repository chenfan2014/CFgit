try:
    1/0
except NameError:
    print "Unknown variable"
except ZeroDivisionError:
    print "Zero be derived"
else:
    print "That is went well"
finally:
    print "Go done"
