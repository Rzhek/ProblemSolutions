n, a, b = map(int, input().split())

dp = [0] * (b + 1)
dp[0] = 1

for _ in range(n):
    for i in range(b, -1, -1):
        dp[i] = sum(dp[max(0,i-6):max(0,i)])

res = sum(dp[a:b+1]) / 6 ** n
print(f"{res:.6f}")