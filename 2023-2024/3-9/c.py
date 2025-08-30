from collections import deque


n = int(input())
dirtiness = numDirty = res = 0
days = deque(map(int, input().split()))
for i in range(1, 366):
    if days and i == days[0]:
        numDirty += 1
        days.popleft()
    dirtiness += numDirty
    if dirtiness >= 20:
        dirtiness = numDirty = 0
        res += 1
if dirtiness > 0:
    res += 1
print(res)