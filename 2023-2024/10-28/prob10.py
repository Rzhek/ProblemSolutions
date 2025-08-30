def f(n, prev1, prev2, memo):
    if n == 0:
        return 1
    if (n, prev1, prev2) in memo:
        return memo[(n, prev1, prev2)]
    res = 0
    for i in range(10):
        if i in [prev1, prev2]:
            continue
        if None in [prev1, prev2] or (None not in [prev1, prev2] and not (i < prev1 < prev2 or i > prev1 > prev2)):
            res += f(n-1, i, prev1, memo)
    memo[(n, prev1, prev2)] = res
    return res

memo = dict()
for _ in range(int(input())):
    num = int(input())
    print(f(num, None, None, memo) % (10 ** 9 + 7))
