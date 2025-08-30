from collections import deque


def addToQ(grid, q, r, c, dr, dc):
    n, m = len(grid), len(grid[0])
    while 0 <= r < n and 0 <= c < m and grid[r][c] in '.F':
        q.append((r, c))
        grid[r][c] = 'F'
        r += dr
        c += dc




for test in range(1, int(input()) + 1):
    n, m = map(int, input().split())
    grid = [list(input().strip()) for _ in range(n)]
    dirs = {'>': (0, 1), '<': (0, -1), 'V': (1, 0), '^': (-1, 0)}

    def valid(r, c, visited = set()):
        return 0 <= r < n and 0 <= c < m and grid[r][c] in '.F' and (r, c) not in visited

    # visited = set()
    for row in range(n):
        for col in range(m):
            if grid[row][col] in dirs:
                dr, dc = dirs[grid[row][col]]
                q = deque()
                # if  0 <= row + dr < n and 0 <= col + dc < m:
                # print(row, col, dr, dc)
                q.append((row, col))
                if dr == 0:
                    addToQ(grid, q, row - 1, col + dc, -1, dc)
                    addToQ(grid, q, row + 1, col + dc, 1, dc)
                else:
                    addToQ(grid, q, row + dr, col - 1, dr, -1)
                    addToQ(grid, q, row + dr, col + 1, dr, 1)

                # print(q)
                    
                for r, c in q:
                    r += dr
                    c += dc
                    while valid(r, c):
                        grid[r][c] = 'F'
                        r += dr
                        c += dc



                # # visited = set()
                # while q:
                #     r, c = q.popleft()
                #     if not (0 <= r < n and 0 <= c < m): continue
                #     if grid[r][c] not in '.F':
                #         if (r, c) != (row, col):
                #             continue
                #     else:
                #         grid[r][c] = 'F'
                    
                #     if (r, c) in visited: continue
                #     visited.add((r, c))
                #     r, c = r + dr, c + dc
                #     R, C = r, c
                #     ran = 0
                #     while valid(R, C, dr, dc, visited):
                #         ran = 1
                #         visited.add((R, C))
                #         grid[R][C] = 'F'
                #         R += dr
                #         C += dc
                    
                #     if not ran: continue
                #     if dr == 0:
                #         q.append((r + 1, c))
                #         q.append((r - 1, c))
                #     else:
                #         q.append((r, c + 1))
                #         q.append((r, c - 1))

                    

                    
                        

                        
    
    print(f'Map #{test}')
    for row in grid:
        print(''.join(row))
    print()

                    

