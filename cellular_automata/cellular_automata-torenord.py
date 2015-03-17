#!/usr/bin/env python

N = 253
M = 2*N+3

def solve():
    A = [False] * M
    A[N+1] = True

    for _ in range(N):
        B = [False] * M

        for i in range(1, M-1):
            if A[i]:
                B[i] = not(A[i-1] and A[i+1])
            else:
                B[i] = A[i-1] or A[i+1]

        A = B

    return sum(A)

print solve()
