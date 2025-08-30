from math import exp

def binarySearch(l, r, target):
    if l == r:
        return l
    mid = (r + l) // 2
    print(f'mid = {mid}')
    error = calcError(mid)
    if abs(error) < 10 ** -4:
        return mid
    if error > 0:
        return binarySearch(l, mid, target)
    else:
        return binarySearch(mid, r, target)


def cosh(d, a):
    x = d / a / 2
    return (exp(x) + exp(-x)) / 2


def sinh(d, a):
    x = d / a / 2
    return (exp(x) - exp(-x)) / 2


def calcError(a):
    newS = a * cosh(d, a)
    print(f'newS = {newS}')
    return newS - s


d, s = map(int, input().split())
a = binarySearch(0.00000001, 10 ** 9, s)
# a = 410.474747252
print(f'a = {a}')
print(f's = {a * cosh(d, a)}')


