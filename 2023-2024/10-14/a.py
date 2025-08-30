r, f = map(int, input().split())

if (round(f / r) % 2):
    print('down')
else:
    print('up')