word = input()
if (word.count('AB') == 0 or word.count('BA') == 0):
    print('NO')
    exit()

res = 'NO'
word1 = word.replace('AB', '--', 1)

if (word1.count('BA') > 0):
    res = 'YES'

word2 = word.replace('BA', '--', 1)
if (word2.count('AB') > 0):
    res = 'YES'

print(res)

