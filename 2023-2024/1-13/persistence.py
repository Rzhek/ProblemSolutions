n = int(input())
steps = 0
while n // 10 != 0:
    newNum = 1
    for i in str(n):
        newNum *= int(i)
    n = newNum
    steps += 1

print(steps)