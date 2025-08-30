
def checkSeq(seq):
    return len(set(seq)) == len(seq)


for _ in range(int(input())):
    seq = input()
    
    for start in range(min(7, len(seq))):
        res = True
        for i in range(0, len(seq), 7):
            if not checkSeq(seq[i + start:i + start + 7]):
                res = False
                break

        res &= checkSeq(seq[:start])

        if res:
            break
    
    if res:
        print(1)
    else:
        print(0)
