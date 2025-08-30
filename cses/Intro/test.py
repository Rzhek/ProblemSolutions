n = int(input())
nums = list(map(int, input().split()))

res = 0
for l in range(0, n):
    for r in range(l + 1, n + 1):
        if (len(set(nums[l:r])) == r - l):
            res += 1
            print(l, r)

print(res)