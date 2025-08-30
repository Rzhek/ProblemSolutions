def getMins(array):
    min1 = min2 = float('inf')
    for i in array:
        if i <= min1:
            min1, min2 = i, min1
        elif i < min2:
            min2 = i
    return min1, min2

t = int(input())

for _ in range(t):
    numArrays = int(input())
    mins1 = []
    mins2 = []
    for __ in range(numArrays):
        input()
        m1, m2 = getMins(list(map(int, input().split())))
        mins1.append(m1)
        mins2.append(m2)
    print(sum(mins2) - min(mins2) + min(mins1))
