n, cur = int(input()), 1
for num in input().split():
    if num == 'mumble' or int(num) == cur: cur += 1
    else:
        print('something is fishy')
        exit()
print('makes sense')
