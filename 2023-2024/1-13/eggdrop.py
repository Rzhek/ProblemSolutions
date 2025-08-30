n, k = map(int, input().split())
max_safe, min_break = 1, k
for _ in range(n):
    floor, status = input().split()
    floor = int(floor)
    if status[0] == 'S':
        max_safe = max(max_safe, floor)
    else:
        min_break = min(min_break, floor)

print(max_safe + 1, min_break - 1)