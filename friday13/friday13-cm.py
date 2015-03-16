import calendar

def solution():
    # Insight: Months MUST be february and march
    year = 2015

    while True:
        year += 1
        if calendar.weekday(year, 2,13) == calendar.FRIDAY:
            return  str(year) + "-02" + " " + str(year) + "-03"

print solution()
