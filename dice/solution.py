from numpy.random import randint
from numpy import min, max, sum

def lo_better(n):
    k = 10000
    lo = min(randint(1, 7, (k, n, 2)), 2)
    hi = max(randint(1, 7, (k, n, 2)), 2)

    lo_score = 2**sum(lo >= hi, 1) - 1
    hi_score = sum(hi > lo, 1)

    return sum(lo_score > hi_score) / float(k) > .5

print (n for n in xrange(100) if lo_better(n)).next()
