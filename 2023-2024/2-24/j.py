n = 66668
seq = [3 * (i // 2) if i % 2 == 0 else -1 for i in range(n)]
seq[-1] = 100000
print(len(seq))

while True:
    num = int(input())
    if num == -1:
        break
    elif num % 3 == 0:
        print(num // 3 * 2 + 1)
    elif seq[num // 3 * 2 + 1] != num:
        print(-1)
        if (num - 1) % 3 == 0:
            seq[num // 3 * 2 + 1] = num + 1
        else:
            seq[num // 3 * 2 + 1] = num - 1
    else:
        print(num // 3 * 2 + 2)

for i in range(n):
    if seq[i] == -1:
        print(seq[i-1] + 1)
    else:
        print(seq[i])
