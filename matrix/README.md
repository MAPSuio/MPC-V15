We are now interested in some special 4x4 matrices that have the following
properties:

1. All elements are integers from 1 through 7 (inclusive)
2. The sum of each row and each column must all be the same
3. The sum of all elements in the entire matrix is twice the sum of the two
   diagonals

How many distinct 4x4 matrices have all these three properties?

Answer: 3789991

----
__Solution__
There are 7<sup>16</sup> ways to fill out a 4x4 matrix with the numbers 1 - 7.
We also need to do some summation to verify a candidate matrix, yielding
~10<sup>14</sup> operations. This means naïve brute-force is out of the
question and would take several hours (if not days).

First observe that if we fill out for instance the 10 marked cells in the
"illustration" below, then the remaining six cells are uniquely determined by
the three properties in the problem statement.

+-+-+-+-+  
|#|#|#|#|  
+-+-+-+-+  
|#|#|#| |  
+-+-+-+-+  
|#|#|#| |  
+-+-+-+-+  
| | | | |  
+-+-+-+-+  

This means that if we brute force the value of these 10 cells, we can quickly
determine the value of the remaining six, and then all that remains is to
check that these six values lie in the range 1 - 7. This gives us
~10<sup>10</sup> operations which can be done in minutes in a fast language
(not Java). In a contest situation this is probably the solution that will give
you the answer first (it is quick to implement).

If we want to do even better we can formulate the properties as a system of
linear equations.

First label the cells in the matrix like this:

+-+-+-+-+  
|a|b|c|d|  
+-+-+-+-+  
|e|f|g|h|  
+-+-+-+-+  
|i|j|k|l|  
+-+-+-+-+  
|m|n|o|p|  
+-+-+-+-+  

The second property can setup through the following seven equations.

First ensure that the rows have the same sum:
a + b + c + d = e + f + g + h  
a + b + c + d = i + j + k + l  
a + b + c + d = m + n + o + p  

Next make sure that the colums have the same sum as the rows:
a + b + c + d = a + e + i + m  
a + b + c + d = b + f + j + n  
a + b + c + d = c + g + k + o  
a + b + c + d = d + h + l + p  

For the third property we need one more equation:
a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p = 2*(a + f + k +
p + c + g + j + m)  

Solving this system is a bit of work on paper, but can be done easily by Matlab
or (not _that_ easily) by Wolfram Alpha. [Example here](sys_solve.m). It turns
out this system has rank 7, which means that seven of the cells are uniquely
determined once the remaining 9 have a value.

The seven resulting equations are:
a = h + l - m  
b = g + k - n  
c = -g - k + m + n + p  
d = -h - l + m + n + o  
e = -h + j + k  
f = -g - j - k + m + n + o + p  
i = -j - k - l + m + n + o + p  

So it turns out that once we've filled out the marked cells in the illustration
below, the remaining seven are uniquely determined. This saves the work of
brute-forcing one more cell!

+-+-+-+-+  
| | | | |  
+-+-+-+-+  
| | |#|#|  
+-+-+-+-+  
| |#|#|#|  
+-+-+-+-+  
|#|#|#|#|  
+-+-+-+-+  

Observe from the equations above that all of the calculated values are integers
as long as all the generated values are integer. So once again we have to check
that the calculated values are in the range 1 - 7. Now we're down to
~10<sup>8</sup> operations, which can be executed in less than 100ms in a fast
language (again, don't use Java for this, that's just silly).
