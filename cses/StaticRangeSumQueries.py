n, q = map(int, input().split())
arr = list(map(int, input().split()))
# print(arr)
for i in range(1, n):
    arr[i] += arr[i-1]
print(arr)
for _ in range(q):
    l, h = map(int, input().split())
    if l > 0 and h > 0:
        print(arr[h-1] - arr[l-1])
    else:
        print(arr[h-1])