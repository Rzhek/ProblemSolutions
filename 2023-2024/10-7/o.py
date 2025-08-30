from math import ceil

a, b, c, d = map(int, input().split())

total = c + d
trucks = ceil(total / a)
total = trucks * a

# at mestre

total -= d

if total % b != 0:
    print('No solution.')
else:
    boats = int(total / b)
    tr = 's' if trucks != 1 else ''
    bo = 's' if boats != 1 else ''
    print(f'We need {trucks} truck{tr} and {boats} boat{bo}.')

