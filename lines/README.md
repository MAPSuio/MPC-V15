The file [points.txt] represents 1000 points in the plane. Each point is
described on a single line by its x-coordinate and y-coordinate (see the file).

The line that runs through the points (0, 0) and (1000, 1000) splits this set
of points in two. How many points are there on the side of the line which has
the most points? (you may assume that no points lie exactly on the line)

Answer: 506

----
### Solution
The line running through (0, 0) and (1000, 1000) happens to be the line y = x.
Thus a point (x<sub>i</sub>, y<sub>i</sub>) is above the line if
y<sub>i</sub> > x<sub>i</sub>, and below otherwise.
