
def f():
    global a, b, x, y, v, h
    
    # (1, y)
    ansy = a * 1 + b
    if h == 1 and -1 <= ansy <= 1 and ansy != y:
        x = 1
        y = ansy
        a = -a
        b = -b
        h = -1
        return
    # (x, 1)
    ansx = (1 - b) / a
    if v == 1 and -1 <= ansx <= 1 and ansx != x:
        x = ansx
        y = 1
        a = -a
        v = -1
        return
    # (-1, y)
    ansy = a * -1 + b
    if h == -1 and -1 <= ansy <= 1 and ansy != y:
        x = 1
        y = ansy
        a = -a
        b = -b
        h = 1
        return
    # (x, -1)
    ansx = (-1 - b) / a
    if v == -1 and -1 <= ansx <= 1 and ansx != x:
        x = ansx
        y = 1
        a = -a
        v = 1
        return




dy, dx, bounces = map(int, input().split())

a = dy / dx
b = dy / dx

x = -1
y = 0

v = 1
h = -1 if a < 0 else 1

print(f'y={a}(x)+{b} | ({x}, {y})')
for i in range(bounces):
    f()
    print(f'y={a}(x)+{b} | ({x}, {y})')
    input()