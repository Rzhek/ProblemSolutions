from math import ceil


n, l, h = map(int, input().split())
seq = [int(input()) for _ in range(n)]

def get_profit(index, size, skip):
    global sums
    return sums[min(n, skip + (index + 1) * size)] - sums[max(0, skip + size * index)]

sums = [0]
for i in seq:
    sums.append(sums[-1] + i)

mi = float('inf')
ma = 0

# print(sums)
# print(get_profit(0, 3, 0))
# print()
for size in range(l, h+1):
    for skip in range(0, size ):
        days = 0
        for index in range(-1, ceil((n-skip) / size)):
            # print(f'size={size} skip={skip} index={index}')
            if get_profit(index, size, skip) > 0:
                days += 1
        
        mi = min(mi, days)
        ma = max(ma, days)

print(mi, ma)