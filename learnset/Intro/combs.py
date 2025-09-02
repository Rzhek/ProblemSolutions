from collections import Counter
from itertools import combinations_with_replacement as bruh

a = list(bruh(range(9), 7))
b = []
for i in a:
    count = Counter(i)
    # print(count)
    if max(count.values()) <= 2:
        b.append(i)
print(*b, sep='\n')
print(len(b))