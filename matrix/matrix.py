from itertools import product

num = 0
lo = 1
hi = 8

for g, h, j, k, l, m, n, o, p in product(*[range(lo, hi) for i in xrange(9)]):
    a = h + l - m
    if a < lo or a >= hi:
        continue

    b = g + k - n
    if b < lo or b >= hi:
        continue

    c = -g - k + m + n + p
    if c < lo or c >= hi:
        continue

    d = -h - l + m + n + o
    if d < lo or d >= hi:
        continue

    e = -h + j + k
    if e < lo or e >= hi:
        continue

    f = -g - j - k + m + n + o + p
    if f < lo or f >= hi:
        continue

    i = -j - k - l + m + n + o + p
    if i < lo or i >= hi:
        continue

    num += 1

print num

'''  a     b     c     d     e     f     g     h     i     j     k     l     m     n     o     p
   a 1     0     0     0     0     0     0    -1     0     0     0    -1     1     0     0     0
   b 0     1     0     0     0     0    -1     0     0     0    -1     0     0     1     0     0
   c 0     0     1     0     0     0     1     0     0     0     1     0    -1    -1     0    -1
   d 0     0     0     1     0     0     0     1     0     0     0     1    -1    -1    -1     0
   e 0     0     0     0     1     0     0     1     0    -1    -1     0     0     0     0     0
   f 0     0     0     0     0     1     1     0     0     1     1     0    -1    -1    -1    -1
   g 0     0     0     0     0     0     0     0     1     1     1     1    -1    -1    -1    -1
   h 0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
'''
