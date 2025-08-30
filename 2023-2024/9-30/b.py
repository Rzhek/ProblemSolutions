
def getProb(comb):
    pass

def backtrack(i, comb):
    if i == 2:
        return 1
        
    


n = int(input())
probs = []

for _ in range(n):
    probs.append(float(input()))


res = backtrack(0, [])