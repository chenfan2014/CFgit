while True:
    try:
        x = input("Enter the first number")
        y = input("Enter the second number")
        value = x/y
        print "Value = %s" % value
    except Exception, e:
        print "error number", e
        print "Invalid input, try again"
    else:
        break
