import math

n, t = map(int, input().split())
seq = []
res = []

for _ in range(n):
    x, y, tm = map(int, input().split())
    seq.append((x, y, tm))

p1 = 0
p2 = 1
for p in range(0, seq[-1][2], t):
    while not seq[p1][2] <= p <= seq[p2][2]:
        p1, p2 = p2, p2 + 1
    # print(f'for p = {p}, p1 and p2 are {p1} and {p2}')
    x2, x1 = seq[p2][0], seq[p1][0]
    y2, y1 = seq[p2][1], seq[p1][1]
    t2, t1 = seq[p2][2], seq[p1][2]
    dx = x2 - x1
    dy = y2 - y1
    dt = t2 - t1
    px = x1 + (p - t1) * dx / dt
    py = y1 + (p - t1) * dy / dt
    # print(f'for p = {p}, px and py are {px} and {py}')
    res.append((px, py, p))

res.append(seq[-1])
actual = gps = 0
for i in range(1, len(seq)):
    dx = seq[i][0] - seq[i-1][0]
    dy = seq[i][1] - seq[i-1][1]
    actual += math.sqrt(dx ** 2 + dy ** 2)

for i in range(1, len(res)):
    dx = res[i][0] - res[i-1][0]
    dy = res[i][1] - res[i-1][1]
    gps += math.sqrt(dx ** 2 + dy ** 2)


ans = (actual - gps) / actual * 100
print(ans)