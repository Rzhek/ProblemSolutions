from collections import defaultdict
import heapq
from math import sin, cos

def polarToRectangle(r, a):
    return (r * cos(a), r * sin(a))


t = int(input())

for _ in range(t):
    edges = []
    # heapq.heappush(edges, (0, polarToRectangle(sc, sa)))

    c, r = map(int, input().split())
    radii = [0, *map(int, input().split())]
    # roads = defaultdict(list)
    for __ in range(r):
        r, a = map(int, input().split())
        # roads[r].append(a)
        heapq.heappush(edges, (r, polarToRectangle(r, a)))
        heapq.heappush(edges, (r+1, polarToRectangle(r+1, a)))
    sc, sa, fc, fa = map(int, input().split())

    print(edges)