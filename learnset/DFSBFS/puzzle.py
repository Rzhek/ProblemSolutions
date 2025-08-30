from collections import deque
from copy import deepcopy


def hash(arr):
    res = 0 
    r = c = 0
    for i in range(3):
        for j in range(3):
            res *= 10
            if arr[i][j] == 0:
                r, c = i, j
            res += arr[i][j]
    return res, r, c

initial = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
precomp = {123456780: 0, }
q = deque([initial])
step = 0
while q:
    for _ in range(len(q)):
        cur = q.popleft()
        hashed, r, c = hash(cur)
        if r > 0:
            new = deepcopy(cur)
            new[r][c], new[r-1][c] = cur[r-1][c], cur[r][c]
            newHash = hash(new)[0]
            if newHash not in precomp:
                precomp[newHash] = step + 1
                q.append(new)
        if r < 2:
            new = deepcopy(cur)
            new[r][c], new[r+1][c] = cur[r+1][c], cur[r][c]
            newHash = hash(new)[0]
            if newHash not in precomp:
                precomp[newHash] = step + 1
                q.append(new)
        if c > 0:
            new = deepcopy(cur)
            new[r][c], new[r][c-1] = cur[r][c-1], cur[r][c]
            newHash = hash(new)[0]
            if newHash not in precomp:
                precomp[newHash] = step + 1
                q.append(new)
        if c < 2:
            new = deepcopy(cur)
            new[r][c], new[r][c+1] = cur[r][c+1], cur[r][c]
            newHash = hash(new)[0]
            if newHash not in precomp:
                precomp[newHash] = step + 1
                q.append(new)
    step += 1

for i in range(int(input())):
    key = 0
    for _ in range(3):
        for j in map(int, input().split()):
            key *= 10
            key += j
    print(precomp[key])
