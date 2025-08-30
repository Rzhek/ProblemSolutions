p1 = input()
p2 = input()

ans = 1
for i, j in zip(p1, p2):
    if i != j:
        ans *= 2

print(ans)