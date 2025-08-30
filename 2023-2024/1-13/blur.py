m, n, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]


def get_avg(arr, i, j):
    summ = 0
    # print(i, j)
    for di in (-1, 0, 1):
        for dj in (-1, 0, 1):
            # print((i + di + n) % n, (j + dj + n) % m, arr[(i + di + n) % n][(j + dj + m) % m])
            summ += arr[(i + di + n) % n][(j + dj + m) % m]
    # print()
    return summ


for _ in range(k):
    new_arr = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            new_arr[i][j] = get_avg(arr, i, j)
    arr = new_arr

colors = set()
for row in arr:
    colors |= set(row)

print(len(colors))
# print(*arr, sep='\n')

