n, lim = map(int, input().split())
nums = [int(input()) for _ in range(2 ** n)]
nums.sort()

ans = 0
for i in range(n):
    cur = 0
    top = nums[-2**i:]
    bot = nums[-2*2**i:-2**i]

    for j in bot:
        if j + lim >= top[cur]:
            cur += 1    
    ans += cur

print(ans)
