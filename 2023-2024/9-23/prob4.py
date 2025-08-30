from functools import reduce
from math import ceil

def factors(n):    
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))).difference({1, n})

p = int(input())

for _ in range(1, p+1):
    n, m = map(int, input().split())
    nums  = []
    ans = set()
    for _ in range(ceil(m / 5)):
        nums.extend(map(int, input().split()))
    for i in nums:
        ans.update(factors(i))
    
    print(n)
    for index, i in enumerate(sorted(ans)):
        print(i, end="\n" if (index+1) % 5 == 0 and index != 0 or index == len(ans)-1 else " ")

