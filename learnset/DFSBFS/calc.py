from collections import deque


for _ in range(int(input())):
    a, b, c, t = map(int, input().split())
    if t == 1:
        print(0)
        continue
    seen = {1}
    q = deque([1])
    steps = 0
    found = False
    while q:
        for __ in range(len(q)):
            cur = q.popleft()
            num1, num2, num3 = (cur + a) % 10e5, (cur * b) % 10e5, cur // c
            for num in (num1, num2, num3):
                if t == num:
                    found = True
                    q = []
                    break
                if num not in seen:
                    seen.add(num)
                    q.append(num)
            else:
                continue
            break
        steps += 1
    
    print(steps + 1 if found else -1)