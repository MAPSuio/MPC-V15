#!/usr/bin/env python

from itertools import product
from hashlib import md5

alphabet = 'abcdefghijklmnopqrstuvwxyz'

def solve():
    i = 1

    while True:
        for x in (''.join(prod) for prod in product(alphabet, repeat=i)):
            if md5(x).hexdigest() == '3a8703f560b3768e0277094c58c686e1':
                return x

        i += 1

print solve()
