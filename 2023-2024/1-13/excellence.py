n = int(input())
people = [int(input()) for _ in range(n)]
people.sort()
res = float('inf')
for i in range(n // 2):
    res = min(res, people[i] + people[n - 1 - i])
print(res)