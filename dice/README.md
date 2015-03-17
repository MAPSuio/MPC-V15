You and an opponent (let's call him Eric) are playing a new dice game you just
invented. The rules are as follows:

The game consists of `n` rounds. In each round both you and Eric throw two die
each. Eric then picks the highest of his two die, you pick the lowest of the
your two die. If Eric's dice is higher than yours, Eric wins the round,
otherwise you win the round.

The score is calculated as follows:
Both players start with a score of `0`.

Whenever Eric wins he simply gets 1 point added to his score.

Whenever you win, your existing score is first doubled, and then you also get 1
point added to your score.

The winner of the game is of course the one with the highest score after the
`n` rounds are completed.

Example play:
Round 1:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your score is now 1

Round 2:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your score is now 2*1 + 1 = 3

Round 3:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your score is now 2*3 + 1 = 7

Round 4:
You throw 5 and 6, Eric throws 3 and 4

You win since 4 < 5, your score is now 2*7 + 1 = 15

---

Now the question is: What is the lowest number of rounds (`n`) the game must be
in order for you to have at least 50% chance of winning?

Answer: 16
