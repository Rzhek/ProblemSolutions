n, m = map(int, input().split())

lst = [[]] + [list() for _ in range(n)]
memo = dict()

for _ in range(m):
    u, v, w = map(int, input().split())
    lst[u].append((v, w))

# print(lst)

def dfs(u):
    if u in memo:
        return memo[u]

    res = 0
    for v, w in lst[u]:
        res = max(res, w + dfs(v))
    memo[u] = res
    return res

res = 0
for u, neighbors in enumerate(lst):
    res = max(res, dfs(u))

print(res)