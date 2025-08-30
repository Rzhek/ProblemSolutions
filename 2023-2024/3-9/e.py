def bt(mine, enemy, n, m, d, memo):
    if m == 0: return 1
    if d == 0: return 0

    key = tuple([tuple(sorted(mine)), tuple(sorted(enemy))])
    if key in memo: return memo[key]

    total = 0
    for i in range(len(mine)):
        if mine[i] == 0: continue
        mine[i] -= 1
        total += bt(mine, enemy, n if mine[i] > 0 else n - 1, m, d - 1, memo)
        mine[i] += 1
    
    for i in range(len(enemy)):
        if enemy[i] == 0: continue
        enemy[i] -= 1
        total += bt(mine, enemy, n, m if enemy[i] > 0 else m - 1, d - 1, memo)
        enemy[i] += 1
    
    memo[key] = total / (n + m)
    return memo[key]


n, m, d = map(int, input().split())
mine = list(map(int, input().split()))
enemy = list(map(int, input().split()))

print(bt(mine, enemy, n, m, d, dict()))
