
def calcSatisfaction(combs, satList):
    res = max(combs, key = lambda x: sum(j * satList[i] for i, j in enumerate(x)))
    return sum(j * satList[i] for i, j in enumerate(res))


def backtrack(comb, i, weight, weightMax, weightList, combs):
    # base case
    # print(f'comb={comb}, i={i}, weight={weight}')
    # input()
    if weight == weightMax:
        combs.append(comb[:])
        return 1
    if weight > weightMax or i == len(weightList):
        return -1
    
    # recursive case
    if i == 0 or comb[i-1] - 2>= comb[i]: 
        comb[i] += 1
        res = backtrack(comb, i, weight+weightList[i], weightMax, weightList, combs)
        comb[i] -= 1

    if i < len(comb) - 1 and comb[i] - 2 >= comb[i+1]:
        comb[i+1] += 1
        res = backtrack(comb, i+1, weight+weightList[i+1], weightMax, weightList, combs)
        comb[i+1] -= 1
    else:
        combs.append(comb[:])
    

t = int(input())
# t = 1

for _ in range(t):
    n, totalWeight = map(int, input().split())
    # n, totalWeight = 4, 10

    w = list(map(int, reversed(input().split())))
    s = list(map(int, reversed(input().split())))
    # w = [2, 3, 1, 1]
    # s = [7, 8, 9, 10]

    combs = [[],]
    backtrack([0] * n, 0, 0, totalWeight, w, combs)

    # print(combs)
    print(calcSatisfaction(combs, s))