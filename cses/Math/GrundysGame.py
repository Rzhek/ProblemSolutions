
def mex(nums):
    nums = list(set(nums))
    nums.sort()
    for i in range(len(nums)):
        if i != nums[i]:
            return i
    return len(nums) 

n = 1222
dp = [0] * (n+1)

for i in range(3, n+1):
    nums = []
    for j in range(1, i // 2 + 1):
        if j == i - j: continue
        nums.append(dp[j] ^ dp[i-j])
    dp[i] = mex(nums)


for _ in range(int(input())):
    N = int(input())
    if (N > n or dp[N]):
        print("first")
    else:
        print("second")