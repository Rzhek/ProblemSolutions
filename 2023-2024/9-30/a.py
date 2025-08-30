from math import floor

string = input()
summ = 0

for i in string:
    summ += ord(i)

summ = floor(summ / len(string))
print(chr(summ))