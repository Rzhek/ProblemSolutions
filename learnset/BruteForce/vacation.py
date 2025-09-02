from collections import defaultdict

best = float('inf')


def getDist(u, v):
    dx = coords[v][0] - coords[u][0]
    dy = coords[v][1] - coords[u][1]
    return (dx ** 2 + dy ** 2) ** .5


def bt(u, visited, d, r):
    global best
    if d > best:
        return
    if len(visited) == r:
        best = min(best, d)
        return

    for v in range(r):
        if v != u and v not in visited and v not in blocked[u]:
            visited.add(v)
            bt(v, visited, d + getDist(u, v), r)
            visited.remove(v)

n = int(input())
for vac in range(n):
    r, b = map(int, input().split())
    coords = [(0, 0,)] + [tuple(map(int, input().split())) for __ in range(r)]
    blocked = defaultdict(set)
    for __ in range(b):
        u, v = map(int, input().split())
        blocked[u].add(v)
        blocked[v].add(u)
    
    best = float('inf')
    bt(0, {0}, 0, r + 1)
    print(f'Vacation #{vac + 1}:')
    if best == float('inf'):
        print('Jimmy should plan this vacation a different day.')
    else:
        print(f'Jimmy can finish all of the rides in %.3f seconds.' % (best + 120 * r))
    print()
    