from datetime import date

y = (y for y in xrange(2016, 10000) if date(y, 2, 13).weekday() == 4).next()
print '%d-02 %d-03' % (y, y)
