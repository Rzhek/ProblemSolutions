from collections import Counter


for test in range(1, int(input()) + 1):
    num = int(input())
    names = []
    for _ in range(num):
        name = input()
        count = Counter(name)
        names.append((name, count))

    names.sort(reverse=True, key=lambda x: tuple(x[1].get(chr(i + ord('A')), 0) for i in range(26)))

    print(f'Class #{test} ordering')
    for name in names:
        print(name[0])
    print()