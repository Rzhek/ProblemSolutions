from heapq import *
h=heappush
i=lambda:map(int, input().split())
n,m=i()
d=[0]*-~n
a=[[]for _ in d]
 
for _ in ' '*m:
    u,v=i()
    a[v]+=u,
    d[u]+=1
 
q=[]
b=[]
[h(q,~u) for u in range(n) if d[u+1]<1]
 
while q:
    u=heappop(q)
    b+=-u,
    for v in a[-u]:
        d[v]-=1
        if d[v]<1:
            h(q,-v)
 
 
                
print(*b[::-1])