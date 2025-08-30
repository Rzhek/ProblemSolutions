from collections import Counter

string = input()
count = Counter(string)
res = 0
for i in sorted(list(count.keys()), key=lambda x: count[x], reverse=True)[2:]:
    res += count[i]
print(res)