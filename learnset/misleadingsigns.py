word1 = input()
word2 = input()
letters = set(input())

for i, j in zip(word1, word2):
    if i != j and (i in letters or j in letters):
        print(True)
        exit()
print(False) 