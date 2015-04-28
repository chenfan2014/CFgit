import os,time
print "Process %s start" % os.getpid()
pid = os.fork()
if pid == 0:
    print "Child process"
else:
    time.sleep(4)
    print "Father process"
