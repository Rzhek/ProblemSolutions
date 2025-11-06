n = int(input())
num = 1
for i in range(n):
    a, b = map(int, input().split())
    num *= a ** b

cnt = 0
sum = 0
prod = 1

mod = 10**9+7
print(num)
factors = set()
for x in range(1, int((num + 1) ** .5 + 1)):
    if num % x == 0:
        factors.add(x)
        factors.add(num // x)

cnt = len(factors)
for f in factors:
    sum = (sum + f) % mod
    prod = (prod * f) % mod
    
print(cnt % mod, sum % mod, prod % mod)