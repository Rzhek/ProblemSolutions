while True:
    num = input()

    if num == '0':
        break

    cur = 0
    n = len(num)
    for index, i in enumerate(reversed(num)):
        cur += int(i) ** (n-index)

    if int(num) == cur:
        print(f'{num} is a powerful number.')
    else:
        print(f'{num} is not a powerful number.')
