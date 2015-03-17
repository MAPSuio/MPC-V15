from random import randint

def sim_lo(n):
    score = 0

    for i in xrange(n):
        if min(randint(1, 6), randint(1, 6)) >= max(randint(1, 6), randint(1, 6)):
            score = 2*score + 1

    return score

def sim_hi(n):
    score = 0

    for i in xrange(n):
        d1, d2 = max(randint(1, 6), randint(1, 6)), max(randint(1, 6), randint(1, 6))
        score += (d1 > d2) + .5*(d1 == d2)

    return score

def lo_better(n):
    lo_score = 0
    hi_score = 0

    for i in xrange(10000):
        lo_score += sim_lo(n)
        hi_score += sim_hi(n)

    return lo_score > hi_score

print (n for n in xrange(100) if lo_better(n)).next()
