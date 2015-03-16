import math

# This follows the reasoning for the original birthday problem
# as presented at Harvard Stat 110 Lecture 3:
# https://www.youtube.com/watch?v=LZ5Wergp_PA

# The key insight is that it is much easier to
# calculate the compliment of the event.

def compliment_probability(minutes, people):

    # The compliment_probability gives the probability
    # that NO two students are born within the same minute

    # Imagine the students enter the room one by one
    # The first student can be born in any minute
    # The second student can be born in any minute except
    # the same as the first student, so  in m-1 minutes.
    # The third student can be born in m-2 minutes etc...

    # Every minute is equally likely. The result follows from
    # the multiplication principle.

    results = []
    for i in range(people):
        term = (minutes - i) / float(minutes)
        results.append(term)

    return reduce(lambda x,y: x*y, results)

def solve(minutes):
    probability = 0
    people = 2

    while probability < 0.5:

        probability = 1 - compliment_probability(minutes, people)
        if probability >= 0.5:
            return people

        people += 1

#print solve(365) # this yields 23, which is correct for the original birthday problem

print solve(365 * 24 * 60)
