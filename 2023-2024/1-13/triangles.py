sides1 = sorted(map(int, input().split()))
sides2 = sorted(map(int, input().split()))

if sides1 != sides2 or sides1[0] ** 2 + sides1[1] ** 2 != sides1[2] ** 2:
    print(0)
else:
    print(1)