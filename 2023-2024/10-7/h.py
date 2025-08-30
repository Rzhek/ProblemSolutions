
n = int(input())
ips = []

for _ in range(n):
    ip = list(map(lambda x: bin(int(x))[2:], input().split('.')))
    for i in range(len(ip)):
        if len(ip[i]) < 8:
            ip[i] = '0' * (8 - len(ip[i])) + ip[i]
    ips.append(''.join(ip))

res = 0
for i in zip(*ips):
    if len(set(i)) != 1:
        break
    res += 1

print(res)
