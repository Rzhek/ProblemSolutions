from collections import deque


n = int(input())

for _ in range(n):
    grid = ''
    for _ in range(3):
        grid += ''.join(input().split())

    q = deque([grid])
    visited = set([grid])
    steps = 0
    target = '123456780'
    if (grid == target):
        print(0)
        continue
    found = False
    while q:
        # print(steps, q)
        for __ in range(len(q)):
            cur = q.popleft()
            ind = cur.index('0')
            if ind < 6:
                # q.append(cur[:ind] + cur[ind])
                pass


        steps += 1
        if found:
            break
    # print(q)
    print(steps)
                        