c = int(input())

for _ in range(c):
    k, n, r = map(int, input().split())

    word = [i for i in range(97, 97 + n *(k+1), k+1)]

    print(97, 97 + n * (k + 1), k+1)
    print("".join(map(chr, word)))