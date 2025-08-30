n = int(input())
points = set()
visited = set()

res = 0
for _ in range(n):
    points.add(tuple(map(int, input().split())))

for x, y in points:
    for dx, dy in [(0, -2018), (0, 2018), (1680, 1118), (-1680, 1118), (1680, -1118), (-1680, -1118)]:
        point1, point2 = (x + dx, y + dy), (x + dy, y + dx)
        if point1 in points and ((x, y), point1) not in visited and (point1, (x, y)) not in visited:
            visited.add(((x, y),point1))
            res += 1
        if point2 in points and ((x, y), point2) not in visited and (point2, (x, y)) not in visited:
            visited.add(((x, y),point2))
            res += 1

# print(points)
print(res)