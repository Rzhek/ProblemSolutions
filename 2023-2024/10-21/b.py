from math import asin, cos, pi, sin, sqrt
from itertools import product

xi, yi = map(int, input().split())
xf, yf = map(int, input().split())

Bx, By, Br = map(float, input().split())
Rx, Ry, Rr = map(float, input().split())

delta1 = sqrt( (xi-Rx) ** 2 + (yi - Ry) ** 2)

d1 = sqrt(delta1 ** 2 - Rr ** 2)
a1 = asin(Rr / d1)

dx1 = d1 * cos(a1)
dy1 = d1 * sin(a1)


delta2 = sqrt( (xf-Rx) ** 2 + (yf - Ry) ** 2)

d2 = sqrt(delta2 ** 2 - Rr ** 2)
a2 = asin(Rr / d2)

dx2 = d2 * cos(a2)
dy2 = d2 * sin(a2)

# print(delta1, d1, a1, dx1, dy1)
# print(delta2, d2, a2, dx2, dy2)


# for p1, p2 in product([(xi + dx1, yi + dy1), ()]

arcLength = (pi - a1 - a2) * Rr

# print(d1 + d2 + (180 - a1 * 180 / pi - a2 * 180 / pi) * pi / 180
print(d1, d2, a1 * 180 / pi)

