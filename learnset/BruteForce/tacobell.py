from itertools import combinations

for _ in range(int(input())):
    n, k = map(int, input().split())
    items = [input() for i in range(n)]
    items.sort()
    combs = list(combinations(items, k))
    for comb in combs:
        print(' '.join(comb))