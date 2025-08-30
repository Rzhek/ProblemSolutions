def T(n):
    return sum(range(1, n + 1))

def W(n):
    return sum([k * T(k + 1) for k in range(1, n + 1)])

for i in range(1, int(input()) + 1):
    n = int(input())
    print(i, n, W(n))