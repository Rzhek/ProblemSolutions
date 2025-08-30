from math import comb
for i in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    dx = x2 - x1
    dy = y2 - y1
    print(comb(dx + dy, dx))