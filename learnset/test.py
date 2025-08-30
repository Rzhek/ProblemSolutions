
from bisect import bisect_left, bisect_right

def solve(profit, cost):
    n = len(profit)
    diff = [profit[i] - cost[i] for i in range(n)]

    diff.sort()

    res = 0
    for l in range(n):
        if (diff[l] == 0):
            r = bisect_left(diff, 1)
            res += n - r
        elif (diff[l] < 0):
            r = bisect_left(diff, -diff[l] + 1)
            res += n - r
        else:
            res += n - l - 1
    
    return res





print(solve([6, 3, 7, 7, 2, 4, 6], [6, 9, 9, 8, 9, 2, 3]))



# [6, 3, 7, 7, 2, 4, 6]
# [6, 9, 9, 8, 9, 2, 3]
# 0 
