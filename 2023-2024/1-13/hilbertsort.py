n, s = map(int, input().split())
points = [tuple(map(int, input().split())) * 2 for i in range(n)]

def f(points, s):
    # print(s, points)
    if len(points) == 1:
        print(*points[0][2:])
    if len(points) <= 1:
        return
    
    s /= 2
    quadrants = [[] for _ in range(4)]
    
    for i, j, x, y in points:
        if i < s and j < s:
            quadrants[0].append((j, i, x, y))
        elif i < s and j >= s:
            quadrants[1].append((i, j - s, x, y))
        elif i >= s and j >= s:
            quadrants[2].append((i - s, j - s, x, y))
        else:
            quadrants[3].append((s - j, s * 2 - i, x, y))
    
    for i in range(4):
        f(quadrants[i], s)

f(points, s)
