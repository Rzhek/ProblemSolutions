

t = int(input())

def backtrack(a, b, comb, elems, res):
    for i in a:
        for j in b:
            if (i, j) not in comb:
                comb.append((i, j))
                bac
for _ in range(t):
    n = int(input())
    
    answer = []

    backtrack(list(range(2 * n)), list(range(2 * n)), [], answer)
    

    



























# import itertools


# def backtrack(comb, b1, b2, i, res):
    
#     for j in range(len(b1)-1):

#         b1[i] += 1
#         b2[j] += 1
#         comb.append((i, j))
#         backtrack(comb, b1, b2, )

# t = int(input())

# for _ in range(t):
#     n = int(input())

#     branch1 = [0] * n
#     branch2 = branch1[:]
#     res = []

#     backtrack([], branch1, branch2, 0, res)
#     print(len(res))
#     print(res)













# a = list(map(lambda x: x[0] + x[1], itertools.product(['A1', 'A2', 'A3'], ['B1', 'B2', 'B3'])))

# b = list(itertools.combinations(a, 6))

# for i in b:
#     i = "-".join(i)
#     if i.count('A1') == i.count('A2') == i.count('A3') == i.count('B1') == i.count('B2') == i.count('B3') == 2:
#         print(i)