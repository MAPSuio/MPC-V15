
def birthday_minute(people, minutes):
    if people > minutes:
        return 0
    sum = 1
    for i in xrange(0, people):
        sum = sum * (1 - (i/(minutes*1.0)))
    return (1-sum)


for i in xrange(2, 160):
    print str(i)+" "+str(birthday_minute(i, 60*24))
