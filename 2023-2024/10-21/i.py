n = int(input())
heroes = list(map(int, input().split()))
villains = list(map(int, input().split()))

days = 0
index = 1

if heroes[0] > villains[0]:
    print(0)
else:
    days = villains[0] - heroes[0]
    while index < len(heroes):
        if heroes[index] + days < villains[index]:
            days += 1
            break
        elif heroes[index] + days > villains[index]:
            break
        index += 1

    print(days)