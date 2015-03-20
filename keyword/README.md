[This file](./graph.tsv) encodes a *directed graph* with 25 nodes, numbered
from 0 through 24. The file consists of 25 rows, each row having 25 columns.
For a given row *i*, the value in column *j*  represents the cost of going from
node *i* to node *j*. If the cost is -1, there is no edge from node *i* to node
*j*. Unless the cost is -1, it will always be positive.

Find the shortest path from node 0 to node 24. For each edge on the path
from node 0 to node 24, print the ascii symbol encoded by
<code>cost of the edge % 128 </code>. For example, if the path consists
of three edges with costs 59, 833 and 1595, the answer is <code>YAY</code>.

The edges must be printed in the order they are visited when starting in node 0
and ending in node 24.

Answer: *A
