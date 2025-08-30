import heapq

a1, m = map(int, input().split())
nums = [i for i in range(1, m * 2)]
heapq.heapify(nums)
used = set()
used.add(a1)
ind = 1
while True:
    # print(ind, '====')
    if a1 == m:
        print(ind)
        exit()
    while True:
        # if ()
        d = heapq.heappop(nums)
        if d in used: continue
        break
    a1 = a1 + d
    ind += 1
    if d == m:
        print(ind)
        exit()
    used.add(d)
    used.add(a1)
