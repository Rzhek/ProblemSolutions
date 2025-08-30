from math import factorial as f
from sys import set_int_max_str_digits
import time

set_int_max_str_digits(int(1e5))

n = f(int(input()))
string = input()

res = []
l = r = 1e9
for i, char in enumerate(string[::-1]):
    if (char == '?'):
        l = min(i, l)
        r = i


ans = n // int(pow(10, l)) % int(pow(10, r - l + 1))

# print(int(pow(10, l)), int(pow(10, r - l + 1)))
ans = str(ans)
while (len(ans) < r - l + 1):
    ans = '0' + ans
print(ans)