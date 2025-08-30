def works(num):
    num = str(num)
    prev = '-'
    for digit in num:
        if digit == prev:
            return False
        prev = digit
    return True


cnt = 0
for num in range(1, int(input()) + 1):
    cnt += int(works(num))

print(cnt)

