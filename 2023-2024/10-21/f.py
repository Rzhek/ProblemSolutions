n = int(input())
seq = list(map(int, input().split()))

n1, n2 = 0, 1
while n1 < max(seq) and n2 < max(seq):
    # print('!', n1, n2)
    n1 += n2
    if n1 == n2 and seq.count(n1) >= 2:
        print(seq.index(n1) + 1, seq.index(n1) + 1 + seq[seq.index(n1)+1:].index(n2) + 1)
        break

    if n1 != n2 and n1 in seq and n2 in seq:
        print(seq.index(n2) + 1, seq.index(n1) + 1)
        break

    n2 += n1
    if n1 != n2 and n1 in seq and n2 in seq:
        print(seq.index(n1) + 1, seq.index(n2) + 1)
        break


else:
    print('impossible')

# 4
# 1 12 67 8

# 6
# 1 5 6 7 90 8