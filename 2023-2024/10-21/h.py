m = int(input())

n = 3

if m == 1:
    print(f'{3} {1}')
    exit()

while 2 ** (n-1) <= m:
    s = 1

    summ = 0
    k = 0
    while summ < m:
        summ += s ** (n - 1)
        s += 1
    
    if summ == m:
        print(n, s-1)
        break

    n += 1
else:
    print('impossible')