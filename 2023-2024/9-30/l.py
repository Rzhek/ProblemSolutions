n, m = map(int, input().split())

teams_max = [0] * m
for i in range(m):
    teams_max[i] = int(input())

teams = [0] * m
number = 1
done = False

while not done:
    for i in range(len(teams)):
        if n == 0:
            done = True
            break
        if teams_max[i] > teams[i]:
            teams[i] += 1
            n -= 1
    if sum(teams_max) == sum(teams):
        break

for i in teams:
    print(i)
