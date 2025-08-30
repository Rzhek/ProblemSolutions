from math import comb

for _ in range(int(input())):
    n, k = map(int, input().split())
    seq = input()
    res = 0
    for i in range(len(seq)):
        if seq[i] == 'O':
            right = seq[:i].count('L')
            left = seq[i+1:].count('L')
            res += comb(left, k) * comb(right, k)
    print(res % 10007)
