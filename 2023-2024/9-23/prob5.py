translate = {
    '0': '',
    '1': 'one',
    '2': 'two',
    '3': 'three',
    '4': 'four',
    '5': 'five',
    '6': 'six',
    '7': 'seven',
    '8': 'eight',
    '9': 'nine',
    '10': 'ten',
    '11': 'eleven',
    '12': 'twelve',
    '13': 'thirteen',
    '14': 'fourteen',
    '15': 'fifteen',
    '16': 'sixteen',
    '17': 'seventeen',
    '18': 'eighteen',
    '19': 'nineteen',
    '20': 'twenty',
    '30': 'thirty',
    '40': 'forty',
    '50': 'fifty',
    '60': 'sixty',
    '70': 'seventy',
    '80': 'eighty',
    '90': 'ninety',
    '00': '',
}

separators = ['', 'thousand', 'million', 'billion', 'trillion', 'quadrillion', 'quintillion']

def getPart(part, k):
    if int(part) == 0:
        return ''
    if len(part) < 3:
        part = '0' * (3-len(part)) + part 
    res = ''

    if part[0] != '0':
        res += translate[part[0]] + ' hundred'
    
    if part[1] != '0':
        if part[1] != '1':
            res += ' ' + translate[part[1]+'0']
            if part[2] != '0':
                res += ' ' + translate[part[2]]
        else:
            res += ' ' + translate[part[1:]]
    else:
        if part[2] != '0':
            res += ' ' + translate[part[2]]
    
    if res != '':
        res += ' ' + separators[k]
    return res.strip()

t = int(input())

for _ in range(t):
    num = input()

    res = ''

    for i in range(0, -len(num), -3):
        res = getPart(num[i-3:i if i != 0 else None], -i//3) + ' ' + res
    
    res = res.strip().replace('  ', ' ')
    print(res)