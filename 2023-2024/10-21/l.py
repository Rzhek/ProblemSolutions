h, w = map(int, input().split())
matrix = []
res = [['.'] * w for _ in range(h)]

for _ in range(h+2):
    matrix.append(list(map(int, input().split())))


for r in range(1, h+1):
    for c in range(1, w+1):
        if matrix[r-1][c-1] > 0:
            res[r-1][c-1] = 'X'
            for dy in range(-1, 2):
                for dx in range(-1, 2):
                    matrix[r+dy][c+dx] -= 1
                    if matrix[r+dy][c+dx] < 0:
                        print('impossible')
                        exit()


for r in matrix:
    for c in r:
        if c != 0:
            print('impossible')
            exit()
else:
    for r in res:
        print(''.join(r))

