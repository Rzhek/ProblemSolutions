def dp(i, j, n, arr, memo):
    if i > j:
        return 0
    if (i, j) in memo:
        return memo[(i, j)]

    if (i + (n - 1 - j)) % 2 == 0:
        res = max(
            arr[i] + dp(i + 1, j, n, arr, memo), 
            arr[j] + dp(i, j - 1, n, arr, memo)
        )
    else:
        res = min(
            -arr[i] + dp(i + 1, j, n, arr, memo), 
            -arr[j] + dp(i, j - 1, n, arr, memo)
        )
    memo[(i, j)] = res
    return res

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(dp(0, n - 1, n, arr, dict()))