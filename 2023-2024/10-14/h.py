ds, ys = map(int, input().split())
dm, ym = map(int, input().split())

a = ys - ds
b = ym - dm

while a != b:
    if a > b:
        b += ym
    else:
        a += ys

print(a)