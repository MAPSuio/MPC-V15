def is_palin(n):
    s = str(n)
    m = len(s)

    return s[:m/2] == s[:m/2-(1-m%2):-1]

pals = [i for i in xrange(100, 1000) if is_palin(i)]
m = len(pals)

print (p + p2 + p3 for i, p, in zip(xrange(m), pals) for j, p2 in zip(xrange(m),
        pals[i+1:]) for p3 in pals[i+j+2:] if is_palin(p + p2 + p3)).next()
