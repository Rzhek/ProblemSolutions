
n1 = 1
n2 = 2
total = 0

for i in range(int(input())):
    total += n1
    n1, n2 = n2, n1 + n2


print(total % 100007)