from math import ceil

morse = {
    'A': '.-', 
    'B': '-...', 
    'C': '-.-.', 
    'D': '-..', 
    'E': '.', 
    'F': '..-.', 
    'G': '--.', 
    'H': '....', 
    'I': '..', 
    'J': '.---', 
    'K': '-.-', 
    'L': '.-..', 
    'M': '--', 
    'N': '-.', 
    'O': '---', 
    'P': '.--.', 
    'Q': '--.-', 
    'R': '.-.', 
    'S': '...', 
    'T': '-', 
    'U': '..-', 
    'V': '...-', 
    'W': '.--', 
    'X': '-..-', 
    'Y': '-.--', 
    'Z': '--..', 
    '0': '-----', 
    '1': '.----', 
    '2': '..---', 
    '3': '...--', 
    '4': '....-', 
    '5': '.....', 
    '6': '-....', 
    '7': '--...', 
    '8': '---..', 
    '9': '----.'
}


string = input()

code1 = ''
code2 = ''
fail = True

for i in string.upper():
    if i in morse:
        code1 += morse[i]
        fail = False

for i in string[::-1].upper():
    if i in morse:
        code2 += morse[i][::-1] 
        fail = False

if code1 == code2 and not fail:
    print('YES')
else:
    print('NO')

# for i in range(ceil(len(string) / 2)):