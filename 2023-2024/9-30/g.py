t = int(input())

for _ in range(t):
    n = input()
    inc = True
    failed = False
    last = '0'
    out = ''

    for c in n:
        if failed:
            out += last
        elif inc and c >= last:
            out += c
            last = c
        elif inc or c <= last:
            inc = False
            out += c
            last = c
        else:
            failed = True
            out += last
    print(out)
