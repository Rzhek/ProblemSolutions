
n = int(input())

lst = [0] * (n+1)
lst[1] = 1

for i in range(len(lst)):
    if i+1 < len(lst):
        lst[i+1] += lst[i]
    if i+2 < len(lst):
        lst[i+2] += lst[i]

print(lst[-1] % 1000007)
