from itertools import combinations


n = int(input())

for _ in range(n):
    b, k = map(int, input().split())
    bags = []
    for __ in range(b):
        bag, *candies = map(int, input().split())
        bags.append( (set(candies)) )

    bags = sorted(bags, key=len, reverse=True)

    maxNum = 0
    for i in combinations(bags, k):
        total = set()
        for k in i:
            total.update(k)
        maxNum = max(maxNum, len(total))
    
    print(maxNum)