database = [
        ['chenfan', 7],
        ['lilin', 5], 
        ['zhengbeilong', 12] 
]
while(1):
    userName = raw_input("userName : ")
    length = raw_input("Input length : ")
    if[userName, int(length)] in database:
        print "Good job\n"
    else:
        print "Again\n"
