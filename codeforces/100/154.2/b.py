t = int(input())

for _ in range(t):
    a = input()
    b = input()
    for i in range(len(a) - 1):
        if a[i] == b[i] == '0' and a[i+1] == b[i+1] == '1':
            print('YES')
            break
    else:
        print('NO')