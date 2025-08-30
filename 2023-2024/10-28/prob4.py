
# memo = dict()

while True:
    target = int(input())
    if target < 0:
        break
    num = 1
    total = 0
    prev = 0
    while int(bin(num)[2:]) <= target:
        # if num in memo:
        #     total += memo[num]
        #     break
        total += int(bin(num)[2:])
        num += 1

    print(total)