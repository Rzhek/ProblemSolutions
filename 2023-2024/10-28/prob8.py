
index = 0
total = 0
while True:
    index += 1
    inp = input()
    if inp.upper() == 'THE END':
        break
    if len(inp) == 0:
        print(f'Line {index} = 0')
        continue
    inp = inp.split()
    curr = len(inp[0])
    for i in inp[1:]:
        curr = curr * 10 ** len(str(len(i))) + len(i)
    print(f'Line {index} = {curr}')
    total += curr

print(f'Sum of file = {total}')