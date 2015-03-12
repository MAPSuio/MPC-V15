from sys import stdin
from numpy import subtract
from numpy.linalg import norm

points = [map(int, line.split()) for line in stdin]
print ' '.join(map(str, max(([norm(subtract(p1, p2)),] + p1 + p2 for i, p1 in zip(xrange(len(points)), points) for p2 in points[i+1:]))[1:]))
