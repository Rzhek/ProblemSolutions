
n = int(input())
min_amount = 0
cur_amount = 0
for _ in range(n):
    cur_amount += int(input())
    min_amount = min(min_amount, cur_amount)

print(-min_amount)