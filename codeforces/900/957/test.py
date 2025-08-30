n = 1
for a in range(1, 10001):
    for b in range(1, a * n):
        string = str(n) * a
        if (str(a * n - b) == string[:-b]):
            print(a, b)

for n in range(1, 101):
    num = int(input())
    for _ in range(num):
        a, b = map(int, input().split())
        res = str(n) * a
        if (str(a * n - b) != res[:-b]):
            print(n, a, b, "WRONG!")

