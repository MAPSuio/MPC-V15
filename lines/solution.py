from sys import stdin

points = [map(int, line.split()) for line in stdin]
num = sum((x < y for x, y in points))

print max(num, len(points) - num)
