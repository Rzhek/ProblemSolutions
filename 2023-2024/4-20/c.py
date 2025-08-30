from collections import defaultdict


n, m = map(int, input().split())
grid = [[0] * n for _ in range(n)]
for _ in range(m):
    val, string = input().split()
    val = int(val)
    for i in range(n):
        for j in range(i + 1, n):
            start = ord(string[i]) - ord('A')
            end = ord(string[j]) - ord('A')
            grid[start][end] += val
            grid[end][start] -= val

memo = defaultdict(int)

def dfs(u, visited, numVisited):
    print(u)
    visited |= (1 << u)
    if (numVisited == n):
        visited ^= (1 << u)
        return 1
    if (u, visited) in memo:
        if memo[(u, visited)] == 1:
            visited ^= (1 << u)
            return 1
        else:
            visited ^= (1 << u)
            return 0
    
    for v in range(n):
        if (visited & (1 << v) or grid[u][v] <= 0):
            continue
        res = dfs(v, visited, numVisited + 1)
        if (res):
            memo[(u, visited)] = 1
            return 1

    
    memo[(u, visited)] = 0
    visited ^= (1 << u)
    return 0


for i in range(n):
    print(chr(ord('A') + i) + ": ", end='')
    if (dfs(i, 0, 1)):
        print('can win')
    else:
        print("can't win")

