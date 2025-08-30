def greedy(amount, coins):
    res = [amount + 1] * (amount + 1)
    for a in range(amount + 1):
        co = 0
        am = a
        for c in coins[::-1]:
            co += am // c
            am %= c
        res[a] = co
    return res

def dp(amount, coins):
    best = [amount + 1] * (amount + 1)
    best[0] = 0
    for a in range(1, amount + 1):
        for c in coins:
            if a - c >= 0:
                best[a] = min(best[a], 1 + best[a - c])
        
    return best

t = int(input())
seq = list(map(int, input().split()))
maxVal = seq[-1] + seq[-2]
for i, z in zip(greedy(maxVal, seq), dp(maxVal, seq)):
    if i != z: 
        print('non-canonical')
        break
else:
    print('canonical')