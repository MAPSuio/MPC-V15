You and an opponent (let's call him Eric) are playing a new dice game you just
invented. The rules are as follows:

The game consists of `n` rounds. In each round both you and Eric throw two dices
each. Eric then picks the highest of his two dices, you pick the lowest of
your two dices. If Eric's dice is higher than yours, Eric wins the round,
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
- You throw 5 and 6, Eric throws 3 and 4
- You win since 4 < 5, your score is now 1

Round 2:
- You throw 5 and 6, Eric throws 3 and 4
- You win since 4 < 5, your score is now 2*1 + 1 = 3

Round 3:
- You throw 5 and 6, Eric throws 3 and 4
- You win since 4 < 5, your score is now 2*3 + 1 = 7

Round 4:
- You throw 5 and 6, Eric throws 3 and 4
- You win since 4 < 5, your score is now 2*7 + 1 = 15

---

Now the question is: What is the lowest number of rounds (`n`) the game must be
in order for you to have at least 50% chance of winning?

Answer: 16

---
__Solution__
The best way to figure this out is simply to simulate a lot of games. Test for
several values of _n_ (from 1 ... 100 for instance); simulate ~10000 games with
_n_ rounds and see who wins.

This _can_ also be solved analytically, but some care must be taken due to the
discrete nature of the scoring system.

First obtain the probability _p_ for you winning a single round. This is _p_ =
301/1296 ≈ 23%.

Next observe that if you win _k_ rounds, you get 2<sup>_k_</sup> - 1 points.
Eric gets _k_ points if he wins _k_ rounds.

This means that in a game of _n_ rounds Eric has an expected score of _n_(1 -
_p_). You on the other hand have an expected score of 2<sup>_n__p_</sup> - 1.

Solve the following inequality:
_n_(1 - _p_) < 2<sup>_n__p_</sup> - 1

This can easily be solved using Wolfram Alpha. We get _n_ > 16.1044, thus
indicating that the answer is 17. It turns out, however, that for _n_ = 16, the
probability of a tied game is really low due to the discretization of your
score. This in turn happens to cause a higher probability of you winning the
game. So much for our analytical approach I guess...
