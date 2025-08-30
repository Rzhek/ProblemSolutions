
saved = dict()

def permute(x, y) -> int:
    paths = 0
    if x == 0 and y == 0:
        return 1

    if y > x:
        if not saved.get((x, y-1)):
            saved[(x, y-1)] = permute(x, y-1)

        paths += saved.get((x, y-1))

    if x > 0:
        if not saved.get((x-1, y)):
            saved[(x-1, y)] = permute(x-1, y)

        paths += saved.get((x-1, y))
    
    saved[x, y] = paths
    return paths

while True:
    n = int(input())
    if n == 0:
        break

    res = permute(n, n)
    print(res)

