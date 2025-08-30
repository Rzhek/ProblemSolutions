import heapq

n, m, f, src, dst = map(int, input().split())
roads = [[] for _ in range(n * 2)]

for _ in range(m):
    u, v, w = map(int, input().split())
    roads[u].append((v, w))
    roads[v].append((u, w))
    roads[u + n].append((v + n, w))
    roads[v + n].append((u + n, w))

for _ in range(f):
    u, v = map(int, input().split())
    roads[u].append((v + n, 0))

pq = [(0, src)]
heapq.heapify(pq)
cost = [float('inf')] * (2 * n)
while pq:
    w, u = heapq.heappop(pq)
    if cost[u] < w: continue
    cost[u] = w
    for v, dw in roads[u]:
        heapq.heappush(pq, (w + dw, v))

print(min(cost[dst], cost[dst + n]))