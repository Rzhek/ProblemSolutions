for _ in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    prev = 1
    works = 1
    res = 0
    for cur in lst:
        if cur == 1 and prev != 1:
            works = 0
            break
        while (cur < prev):
            res += 1
            cur *= cur
        prev = cur
    
    if not works: print(-1)
    else: print(res)