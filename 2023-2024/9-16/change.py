n = int(input())

for setNum in range(1, n+1):
    num = int(input())
    nums = sorted(list(map(int, input().split())))
    total = 1
    for i in nums:
        if i > total:
            break
        total += i
    
    print(f'Set #{setNum}: {total}\n')

