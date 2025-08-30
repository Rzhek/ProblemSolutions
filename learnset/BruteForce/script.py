lst = []
data = input()
while data != '0':
    lst.append(data)
    res = 0
    for ch in data:
        res += ord(ch) - ord('a') + 1
    if res != 42:
        print(data)
    data = input()

print(lst == sorted(lst))