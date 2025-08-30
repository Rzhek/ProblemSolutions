
p = 1 - float(input())

e = []
fail = True

for N in range(2, 17):
    P = p ** N
    E = P + N * (1 - P)
    e.append( E / N )
    if E < N:
        fail = False
    
if fail:
    print(1)
else:
    minnum = float('inf')
    for index, i in enumerate(e):
        minnum = min(minnum, i)
    
    print(e.index(minnum) + 2)