n = int(input())
seq = list(map(int, input().split()))
res = 0
mi = 0
ma = seq[0]

for i in range(1, len(seq)):
    curr = seq[i]
    mi, ma = max(0, curr - ma), curr - mi

    if ma < 0:
        print(0)
        break

else:
    print(ma - mi + 1)
