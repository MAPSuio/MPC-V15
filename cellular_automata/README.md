# Cellular Automata

Assume S is a string that is infinite in size in both directions. The string consists solely of whitespace, except for at one index which is inhabited by the character 'x'. The string develops according to the following rules, which are applied every minute:

- If a whitespace character has at least one neighbour character 'x' at minute i, it becomes inhabited by an 'x' at minute i+1.
- If an 'x' has one, and only one neighbour character 'x' at minute i, it continues to live at minute i+1.
- If an 'x' has two neighbour characters 'x' at minute i, it dies and becomes a whitespace at minute i+1.

For example, assume we have the substring "\_\_\_x\_\_\_" (where whitespace is denoted with underscore). After one rule application we get "\_\_xxx\_\_", and after two rule applications we get "\_xx\_xx\_". So after 2 minutes there are 4 'x' character on the string.

How many 'x' characters are there one in the string after 253 minutes?

## Solution

Answer: 256
