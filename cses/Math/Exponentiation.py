
mod = int(1e9+7)

def fast(a, b):
    if (b == 0): return 1
    if (b == 1): return a
    res = fast(a, b // 2)
    res = res * res % mod
    if (b & 1): res = res * a % mod
    return res

for _ in range(int(input())):
    a, b = map(int, input().split())
    print(fast(a, b))