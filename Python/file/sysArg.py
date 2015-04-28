#!usr/bin/env python
#-*- coding : utf-8 -*-
import sys
import string

print "Hello"
try:
    sys.exit(1)
except SystemExit:
    pass 
    print "China"
print "Beijing"

class Redirect:
    def __init__(self, stdout):
        self.stdout = stdout
    def write(self, s):
        self.stdout.write(string.lower(s))
oldStdout = sys.stdout
sys.stdout = Redirect(sys.stdout)
print "Heja sverige"
print "DFADFAFDFAGAFD"

sys.stdout = oldStdout

print "FDAFDAFA"

print "\n\n\n"


print "Script name is ", sys.argv[0]
if len(sys.argv) > 1:
    print "There are ", len(sys.argv) - 1, "arguments"
    for arg in sys.argv[1:]:
        print arg
else:
    print "There has no arguments"


print "Path has ", len(sys.path), "member"

def dump(module):
    print module, "=>",
    if module in sys.builtin_module_names:
        print "<BUINTIN>"
    else:
        module = __import__(module)
        print module.__file__
dump("os")
dump("sys")
dump("string")
dump("strop")
dump("zlib")




if sys.platform == "win32":
    import ntpath
    pathmodule = ntpath
elif sys.platform == "mac":
    import macpath
    pathmodule = macpath
else:
# assume it's a posix platform
    import posixpath
    pathmodule = posixpath
print pathmodule



