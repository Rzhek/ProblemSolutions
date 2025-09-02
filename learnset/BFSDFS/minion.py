from collections import defaultdict, deque


for _ in range(int(input())):
    t = int(input())
    trials = {input() for __ in range(t)}
    n, e = map(int, input().split())
    lst = defaultdict(set)
    for __ in range(e):
        u, v, trial = input().split()
        u, v = int(u), int(v)
        lst[u].add((v, trial))
        lst[v].add((u, trial))

    q = deque([0])
    visited = {0}
    res = 0
    while q and not res:
        u = q.popleft()
        for v, trial in lst[u]:
            if v not in visited and trial not in trials:
                if v == n - 1:
                    res = 1
                    break
                q.append(v)
                visited.add(v)
    
    print(res)