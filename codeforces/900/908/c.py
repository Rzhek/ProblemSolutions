t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    seq = list(map(int, input().split()))
    k = min(k, n)
    last = n - 1
    for i in range(k):
        if seq[last] > n:
            print('No')
            break
        last = last + n - seq[last]
        if last >= n:
            last -= n
    else:
        print('Yes')

