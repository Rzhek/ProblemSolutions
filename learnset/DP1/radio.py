for case in range(int(input())):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    arr.sort(key=lambda x: x[0])
    for i in range(1, n):
        maxAdd = 0
        for j in range(i - 1, -1, -1):
            if arr[j][0] + arr[j][2] <= arr[i][0]:
                maxAdd = max(maxAdd, arr[j][1])
        arr[i][1] += maxAdd
    print(max(arr, key=lambda x: x[1])[1])