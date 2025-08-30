
for _ in range(int(input())):
    n = int(input())

    i = 0
    summ = 0
    for j in range(n):
        seq = list(map(int, input().split()))
        # print(i, seq)
        summ += seq[i]
        if i == 0:
            i = 2
        else:
            i -= 1
    
    print(summ)