h, k, v, s = map(int, input().split())
d = 0

while h > 0:
    v += s
    v -= max(1, int(v / 10))
    if v >= k:
        h+=1
    elif v > 0:
        h -= 1
        if h <= 0:
            v = 0
    else:
        h = v = 0
    d += v
    s = max(0, s-1)

print(d)