You and an opponent (let's call him Eric) are playing a new dice game you just
invented. The rules are as follows:

The game consists of `n` rounds. In each round both you and Eric throw two die
each, select one of the two die and compare the die you've selected. *Eric always picks the largest of his two die.*

Before the game starts, you can choose between two strategies:

1. Always play the largest dice
    In this case you get half a point if your die and Eric's die have the
    same value, and 1 point if yours is higher.

2. Always play the lowest dice
    You get 1 point if you beat Eric, 1 point if the dice are the same
    _and_ each time you win 1 point, you also _double your pot_ prior
    to adding the point.
    
The winner of the game is the one with the most points after `n` rounds. Notice that there is no way to lose accumulated points.

Example using strategy 2:
Round 1:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your pot is now 1

Round 2:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your pot is now 2*1 + 1 = 3

Round 3:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your pot is now 2*3 + 1 = 7

Round 4:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your pot is now 2*7 + 1 = 15

---

Now the question is: What is the lowest number of rounds (`n`) the game must be
in order for strategy 2 to the best strategy?

Answer: 8
