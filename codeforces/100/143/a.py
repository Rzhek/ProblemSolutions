n = int(input())
res = 0
for _ in range(n):
    res += sum(map(int, input().split())) >= 2

print(res)