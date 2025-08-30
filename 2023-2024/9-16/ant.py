import heapq

n = int(input())

for campus in range(1, n+1):
    h, t = map(int, input().split())
    edges = []
    graphs = [{i} for i in range(1, h+1)]
    total = 0
    for _ in range(t):
        u, v, w = tuple(map(int, input().split()))
        heapq.heappush(edges, (w, (u, v)))
    
    while edges:
        w, (u, v) = heapq.heappop(edges)
        main = None
        for index, i in enumerate(graphs):
            if (u in i or v in i):
                if (u in i and v in i):
                    break
                if main:
                    main.update(graphs.pop(index))
                    total += w
                    break
                else:
                    main = i
        if len(graphs) == 0:
            break
        
    if len(graphs) > 1:
        total = 'I\'m a programmer, not a miracle worker!'
    print(f"Campus #{campus}: {total}")
