from math import comb
for _ in range(int(input())):
    r, s, x, y, w = map(int, input().split())
    prob = (s-r+1) / s
    tot = 0
    for i in range(x, y + 1):
        tot += comb(y, i) * prob ** i * (1-prob) ** (y - i)
    if tot * w > 1: print("yes")
    else: print("no")