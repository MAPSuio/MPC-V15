A palindrome is a number that is the same "forwards and backwards". For instance,
12321 and 1331 are palindromes. More precisely, a number is palindromic if
the *i*-th first digit is the same as the *i*-th last digit.

We are interested in the smallest three-digit palindrome that can be written as
the sum of three *unique* three-digit palindromes.

Answer: 333

---
__Solution__
The only sensible way to solve this is to brute force. Since there are only
three digits there are very few numbers to try.

On paper: What are the three smallest three-digit palindromes? (101, 111 and
121) What is the sum of these palindromes? (333)

On a larger scale it would make sense to precache the palindromes so you can
quickly find the next palindrome. In this type of contest that would typically
be a waste of time, however.
