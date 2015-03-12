from sys import stdin
from math import log

print max(zip((b*log(a) for a, b in (map(int, line.split()) for line in stdin)), xrange(1000)))[1]
