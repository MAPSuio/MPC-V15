# -*- coding: utf-8 -*-
from sys import stdin

geeks = set([]);
nerds = set([]);

nerdy_interests = ["Category Theory", "DTrace", "Chess", "Linear Algebra", "Quantum Mechanics", "Neuroscience"]
geeky_interests = [ "Dungeons & Dragons", "Magic: The Gathering", "Star Wars", "Pokémon", "Comics"]

name = ""
interest = ""

for line in stdin:
    name = line.split()[0]
    interest = " ".join(line.split()[1:])

    if interest in nerdy_interests:
        nerds.add(name)

    if interest in geeky_interests:
        geeks.add(name)

print len(geeks.intersection(nerds))
