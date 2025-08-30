from collections import defaultdict
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    d = defaultdict(int)
    for i in a:
        d[i % k] += 1
    
    if d[0] > 0:
        print(0)
    elif k == 4:
        if d[2] >= 2:
            print(0)
        elif d[2] == 1:
            print(1)
        elif d[3] > 0:
            print(1)
        else:
            print(2)
    else:
        print(k - max(d.keys()))
