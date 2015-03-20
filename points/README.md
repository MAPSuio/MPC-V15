The file [points.txt] represents 1000 points in the plane. Each point is
described on a single line by its x-coordinate and y-coordinate (see the file).

What two points lie the furthest apart (in euclidean distance)?

The answer should be formatted as `a b c d`, where (a, b) comes before
(c, d) in the file.

Example:
If the points (124, 533) and (925, 436) happened to be the two points that are
the furthest away from each other, the answer would be `124 533 925 436`, since
(124, 533) comes before (925, 436) in the list.

Answer: 997 19 14 994

---
__Solution__
In this contest: Brute force. Run through all pairs of points (there are 10<sup>6</sup> such
pairs), pick the pair with the largest distance.

On a larger scale (more points) a key observation is that all coordinates are
integer and contained in a rather limited range (-1000 ... 1000). Another
observation is that the two most distant points always lie on the boundary of
the convex hull of all the points. This hull will consist of relatively few points since we're using
small integer coordinates. This gives us a faster approach:

First find the convex hull of the points (this takes O(n log n) time using e.g.
Graham scan).  Check the distance between each pair of each vertex
on the hull polygon (takes O(h<sup>2</sup>) time where _h_ << _n_ is the number
of vertices of the hull polygon).
