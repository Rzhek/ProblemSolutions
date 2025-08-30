t = int(input())

for _ in range(t):
    res = 0
    chest, key, stamina = map(int, input().split())
    if key > chest:
        if key - chest > stamina:
            chest += stamina
            res += key
            res += key - chest
        else:
            res = key
    else:
        res = chest

    print(res)