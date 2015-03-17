################################################################################
# An awfully slow simulation of the game that suggests that
# the probability of strategy 2 winning >50% Happens for games of 16
# rounds or more

# Took well over two minutes and ate a lot of ram on my macbook.
# There is no pruning what so ever.

################################################################################


# First, we calculate the probabilities of win, lose or draw in a single round
paths = 0
beneficial_you = 0
beneficial_eric = 0
even = 0

for i in range(1, 6+1):
    for j in range(1, 6+1):
        for k in range(1, 6+1):
            for l in range(1, 6+1):
                paths += 1
                your_choice = min(i, j)
                erics_choice = max(k, l)

                if your_choice > erics_choice:
                    beneficial_you += 1
                elif your_choice == erics_choice:
                    even += 1
                else:
                    beneficial_eric += 1

proability_win_you = float(beneficial_you) / float(paths)
proability_win_eric = float(beneficial_eric) / float(paths)
probability_even = float(even) / float(paths)

# At a given point in the game tree, spawn three child nodes
# for different outcomes of the game

def spawn(li):
    eric_points, you_points, probability_to_here = li

    you_win = [eric_points, (you_points*2) + 1, (probability_to_here * proability_win_you)]
    draw = [eric_points + 0.5, (you_points*2) + 1, (probability_to_here * probability_even)]
    eric_win = [eric_points + 1, you_points, (probability_to_here * proability_win_eric)]

    return [you_win, draw, eric_win]

def prob_win_game(li):

    cum_prob = 0

    for elem in li:
        eric_points, you_points, prob = elem

        if you_points > eric_points:
            cum_prob += prob

    return cum_prob

state = [[0,0,1]]
rounds = 0
prob = 0
while prob < 0.5:

    newstate = []

    for elem in state:

        children = spawn(elem)
        newstate.append(children[0])
        newstate.append(children[1])
        newstate.append(children[2])

    state = newstate
    prob = prob_win_game(state)
    print prob
    rounds += 1

print rounds
