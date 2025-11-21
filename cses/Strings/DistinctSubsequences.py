d={}
r=0
for s in input():
    d[s], r = r, 2*r-d.get(s, -1)
    r %= 10**9+7
print(r)