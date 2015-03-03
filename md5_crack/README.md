MD5 cracking:

You have cracked your way Sony (Again!) and you found your friends account. You would like to know his password, but currently you only have the MD5 salt.
3a8703f560b3768e0277094c58c686e1
He has hinted that the password contains only letters in lower case.

Correct solution: ghjkl

Solution method:
* Testing: echo -n ghjkl | md5sum
* Method 1: google the hash, any difficulty we can give already exists on the net.
* Method 2; actually write code to brute force:
  * Times are for ghjkl, alphabetically sorted search, length 5
    * test.c has an implementation of MD5, this is probably the worst way to solve it (0.6s)
    * test2.c bruteforces with a fast library (This is very fast! 0.5s)
    * test.py bruteforces with a python library (Slowest at 2.8s)
    * test.py can also be run with pypy, this yields 2.4 seconds (hashlib is not optimized further)
  * You have to try all combinations to get there. That is, a-z.
  * 5 chars gives results within seconds, 6 chars gives results probably within minutes
  * For every extra character, the estimated time can be multiplied by 26. python will then use minutes.
