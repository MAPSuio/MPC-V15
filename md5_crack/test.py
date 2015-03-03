from hashlib import md5
from sys import exit


sum = "3a8703f560b3768e0277094c58c686e1"

MAXLEN = 20


def test(s):
    if md5(s).hexdigest() == sum:
        print s
        exit(0)

def recurse(s, l):
    if l == 0:
        test(s)
        return
    s0 = s
    for i in xrange(ord('a'), ord('z')+1):
        s1 = s0 + chr(i)
        recurse(s1, l-1)


for i in xrange(1, MAXLEN+1):
    print "Testing length "+str(i)
    recurse("", i)
exit(1)
