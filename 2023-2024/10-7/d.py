from math import gcd

num = input()
res = 0

for index, i in enumerate(num[::-1]):
    res += int(i) * (1.5) ** index


if res == int(res):
    print(int(res))
else:
    remainder = res - int(res)
    d = 1
    while remainder != int(remainder):
        remainder *= 2
        d *= 2
    
    print(f'{int(res)} {int(remainder)}/{int(d)}')