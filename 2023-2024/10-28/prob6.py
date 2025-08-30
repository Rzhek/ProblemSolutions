t = int(input())

def insertLeft(lst):
    for i in range(1, len(lst)):
        if lst[i-1] + 1 < lst[i]:
            lst.insert(i, lst[i-1] + 1)
            return

def insertRight(lst):
    for i in range(len(lst)-2, -1, -1):
        if lst[i+1] - 1 > lst[i]:
            lst.insert(i+1, lst[i+1] - 1)
            return

for i in range(t):
    n = int(input())
    seq = list(map(int, input().split()))
    seq.sort()
    res = 0
    while max(seq) - min(seq) != n - 1:
        diffL = seq[1] - seq[0]
        diffR = seq[-1] - seq[-2]
        # print(seq, diffL, diffR)
        res += 1
        if diffL < diffR:
            seq.pop(0)
            insertRight(seq)
        else:
            seq.pop()
            insertLeft(seq)
    
    print(res)