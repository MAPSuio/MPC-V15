The file [power.txt] contains 1000 lines, each with two numbers a<sub>i</sub>
and b<sub>i</sub>. Each line represents a power, namely
a<sub>i</sub><sup>b<sub>i</sub></sup>.

Now we want to know; which line (0-indexed) contains the largest number?

Answer: 550

### Solution
What we really need to do in order to find the largest number is to make
comparisons on the form:

a<sub>i</sub><sup>b<sub>i</sub></sup> < a<sub>j</sub><sup>b<sub>j</sub></sup>

The issue is that exponetiation like this quickly leads to large numbers
(_really_ large numbers). Using `int` or `long` is out of the question. Java's
`BigInteger` or Python's `int` would work in theory, but is way too slow for
you to get your answer before the contest end.

One trick with such exponents is to use logarithms. There are two things we
need to know about the `log`-function for this to work. First of all the
`log`-function is _strictly increasing_, which means that we can apply it to
both sides of an inequality.

Next we have the nice property that:

log(a<sub>i</sub><sup>b<sub>i</sub></sup>) = b<sub>i</sub> * log(a<sub>i</sub>)

This means that we can do the comparisons this way instead:

b<sub>i</sub> * log(a<sub>i</sub>) < b<sub>j</sub> * log(a<sub>j</sub>)

This can easily be done using standard `float` and will get the correct result.
