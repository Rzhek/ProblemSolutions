from collections import deque


for _ in range(int(input())):
    n, m = map(int, input().split())
    grid = []
    q = deque([])
    res = 0
    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    for r in range(n):
        grid.append(list(input()))
        for c in range(m):
            if grid[r][c] == 'X':
                res += 1
                q.append((r, c))
                grid[r][c] = '.'
    
    while q:
        row, col = q.pop()
        for dr, dc in dirs:
            r, c = row + dr, col + dc
            if 0 <= r < n and 0 <= c < m and grid[r][c] == '~':
                q.append((r, c))
                grid[r][c] = '.'
                res += 1
    
    print(res * 5)

