n = int(input())

for case in range(1, n+1):
    c = int(input())
    s1 = input()
    s2 = input()
    target = input()

    step = 0
    initial = s1+s2
    if initial == target:
        print(f"{case} 0")
        continue
    current = ""
    while True:
        step+=1
        for i1, i2 in zip(s1, s2):
            current += i2 + i1
        if current == initial:
            print(f"{case} -1")
            break
        if current == target:
            print(f"{case} {step}")
            break
        s1 = current[:c]
        s2 = current[c:]
        # print(step, current, s1, s2)
        # input()
        current = ""
