target = tuple(map(int, input().split()))
n = int(input())
seq = [input()[0] for _ in range(n)]

def sim(x, y, kx, ky, start):
    for i in seq[start:]:
        if i == 'F':
            x, y = x + kx, y + ky
        elif i == 'L':
            kx, ky = -ky, kx
        elif i == 'R':
            kx, ky = ky, -kx
    return x, y

x, y = 0, 0
kx, ky = 0, 1

for i in range(n):
    initial = seq[i]
    if initial != 'F':
        seq[i] = 'F'
        if target == sim(x, y, kx, ky, i):
            print(i + 1, 'Forward')
            break
    if initial != 'L':
        seq[i] = 'L'
        if target == sim(x, y, kx, ky, i):
            print(i + 1, 'Left')
            break
    if initial != 'R':
        seq[i] = 'R'
        if target == sim(x, y, kx, ky, i):
            print(i + 1, 'Right')
            break
    if initial == 'F':
        x, y = x + kx, y + ky
    elif initial == 'L':
        kx, ky = -ky, kx
    elif initial == 'R':
        kx, ky = ky, -kx
    

# 3 2
# 11
# Forward
# Right
# Forward
# Forward
# Left
# Forward
# Forward
# Right
# Forward
# Right
# Forward