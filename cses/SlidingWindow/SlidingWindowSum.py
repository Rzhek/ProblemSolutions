n,k,*[x,a,b,c]=map(int,open(0).read().split())
y=x
r=w=0
for i in range(n):
    w+=x
    x=(a*x+b)%c
    if i>=k-1:
        r^=w
        w-=y
        y=(a*y+b)%c
print(r)