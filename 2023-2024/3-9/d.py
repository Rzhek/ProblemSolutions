import heapq
from typing import Tuple


n, m = map(int, input().split())
inf = float('inf')

edges = [[inf] * n for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    u, v = u - 1, v - 1
    edges[u][v] = w
    edges[v][u] = w

for i in range(n): edges[i][i] = 0

k = int(input())
orders = []
for _ in range(k):
    s, u, t = map(int, input().split())
    u -= 1
    orders.append((s, u, t))

# for i in range(n):
#     for u in range(n):
#         for v in range(n):
#             edges[u][v] = edges[v][u] = min(edges[u][v], edges[u][i] + edges[i][v])

for start in range(n):
    q = []
    for v in range(n):
        if edges[start][v] != inf:
            heapq.heappush(q, (edges[start][v], v))
    while q:
        # print(q)
        w1, u = heapq.heappop(q)
        for v in range(n):
            w2 = edges[u][v]
            if w2 != inf and w1 + w2 < edges[start][v]:
                edges[start][v] = w1 + w2
                heapq.heappush(q, (w1 + w2, v))


def deliver(i, j, time) -> Tuple[int, int]:
    waitTime = 0
    curNode = 0
    for next in range(i, j + 1):
        s, u, t = orders[next]
        time += edges[curNode][u]
        waitTime = max(waitTime, time - s)
        curNode = u
    time += edges[curNode][0]
    return waitTime, time


memo = dict()
def dp(i, j, time) -> int:
    # print(i, j, time)
    # print(i)
    if j >= k:
        return deliver(i, j - 1, time)[0]
    
    # take
    s, u, t = orders[j]
    time = max(time, t)

    if (i, time) in memo:
        return memo[(i, time)]
    
    # option 1: Deliver
    res1, time1 = deliver(i, j, time)
    res1 = max(res1, dp(j + 1, j + 1, time1))

    # option 2: Wait for one more
    res2 = dp(i, j + 1, time)

    res = min(res1, res2)
    memo[(i, time)] = res
    return res

print(dp(0, 0, 0))



# print(*edges, sep='\n')