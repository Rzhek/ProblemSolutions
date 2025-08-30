mod = 1e9+7

def dp(n, prev, arr, memo):
    if n == 0:
        return 1
    if n < 0:
        return 0
    if n in memo:
        return memo[n]
    
    res = 0
    for i in arr:
        if i > prev: continue
        res += dp(n - i, i, arr, memo)
        res %= mod
    memo[n] = res
    return res

for _ in range(int(input())):
    amount, num, *coins = map(int, input().split())
    coins.reverse()
    memo = dict()
    print(dp(amount, float('inf'), coins, memo))
    print(memo)