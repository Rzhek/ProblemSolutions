for _ in range(int(input())):
    a, b, c, d = map(float, input().split())
    print("%.2f" % (a * c + b * d))