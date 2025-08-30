from collections import Counter
from math import ceil


fact = [1, 1]
for i in range(2, 17):
    fact.append(fact[-1] * i)

while True:
    inp = input()
    if inp == '# 0':
        break
    comb, num = inp.split()
    comb = list(sorted(comb))
    num = int(num)

    total = len(comb)
    counter = Counter(comb)
    newCounter = dict()
    for i in counter:
        if counter[i] > 1:
            newCounter[i] = counter[i]

    answer = ''
    while len(comb) > 1:
        div = 1
        for i in newCounter.values():
            div *= fact[i]
        index = ceil(num * div / fact[total - 1])
        num %= fact[total - 1] / div
        letter = comb.pop((index - 1 + total % total))
        if letter in newCounter:
            if newCounter[letter] > 2:
                newCounter[letter] -= 1
            else:
                newCounter.pop(letter)
        answer += letter
        total -= 1
    answer += comb.pop()
    print(answer)
