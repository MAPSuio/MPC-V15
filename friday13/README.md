We are now interested in friday the 13th, especially consecutive months with
friday the 13th.

For instance this year, we had friday the 13th both in Febuary and March, which
are consecutive months. When is the next time (from today) Friday
the 13th will occur in two consecutive months?

The answer should specify both of the consecutive months by year and month
number. For instance, for Feb and March 2015; `2015-02 2015-03`

----
Answer:
`2026-02 2026-03`

----
### Solution
This can simply be brute-forced, preferably using some date-library.

Some observations:
The only way for two consecutive months to have friday the 13th is if the first
month has the same number of days as a whole number of weeks. The only month
that has this property is Febuary in a non-leap year. Thus we only need to find
the next year where the 13th of Febuary is a friday.
