
from math import *

def bl(x):
    return int(1+floor(log(x,2)))

def sol(m,n):
    return m ^ (n << (bl(m)-bl(n)))

print(sol(2888816585588551,43046721))
