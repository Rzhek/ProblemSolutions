from collections import deque


n = int(input())
coords = deque(list(map(int, input().split())))
cube = [[[0 for x in range(n)] for y in range(n)] for z in range(n)]
dirs = [(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0)]

for x in range(n):
    for y in range(n):
        for z in range(n):
            cube[x][y][z] = coords.popleft()

for test in range(1, int(input()) + 1):
    q = deque([tuple(map(int, input().split()))])
    res = 0
    while q:
        X, Y, Z = q.popleft()
        if not cube[X][Y][Z]: continue
        for dx, dy, dz in dirs:
            x, y, z = X + dx, Y + dy, Z + dz
            if (0 <= x < n and 0 <= y < n and 0 <= z < n and cube[x][y][z]):
                pass