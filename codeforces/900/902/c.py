t = int(input())

for _ in range(t):
    n, m, k = map(int, input().split())
    count = 0
    if k == 1:
        count = 1
    elif k == 2:
        if m <= n:
            count = m
        else:
            count = n + (m - n) // n
    elif k == 3:
        if m <= n:
            count = 0
        elif m > n:
            count = m - n - (m - n) // n
        
                
    print(count)