a, b = map(int, input().split())

def works(num):
    num = str(num)
    for i in range(1, len(num)):
        if num[i] == num[i-1]: return 0
    return 1

res = 0
for i in range(a, b + 1):
    res += works(i)

print(res)