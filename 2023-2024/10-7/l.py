word = input()

for i in range(7):
    guess = input()
    if guess == word:
        print('WINNER')
        exit()
    if i == 6:
        print('LOSER')
        exit()
    
    output = ''
    for i, j in zip(guess, word):
        if i == j:
            output += 'G'
        elif i in word:
            output += 'Y'
        else:
            output += 'X'
    print(output)