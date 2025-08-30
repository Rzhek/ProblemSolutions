from math import comb
mod = int(1e9+7)

for _ in range(int(input())):
    n, k = map(int, input().split())
    num1 = num0 = 0
    for i in input().split():
        if (i == '1'): num1 += 1
        else: num0 += 1
    
    res = 0
    for i in range(k // 2 + 1, k + 1):
        res += comb(num1, i) * comb(num0, k - i)
        res %= mod
    
    print(res)