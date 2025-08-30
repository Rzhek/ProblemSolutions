t = int(input())

for _ in range(t):
    n, *seq = map(int, input().split())
    for i in range(1, len(seq) - 1):
        if seq[i] - 1 != seq[i - 1]:
            print(i + 1)
            break
    else:
        print(len(seq))