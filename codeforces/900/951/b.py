from itertools import zip_longest
for _ in range(int(input())):
    x, y = map(lambda z : bin(int(z))[:1:-1], input().split())
    ans = 0
    for i, j in zip_longest(x, y, fillvalue='0'):
        if (i == j): ans += 1
        else: break
    print(2 ** ans)