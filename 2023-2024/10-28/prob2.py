from collections import Counter

def bt(index, original, count):
    if index == len(original):
        return 1
    res = 0
    for i in set(original):
        if original[index] != i and count[i] > 0:
            count[i] -= 1
            res += bt(index + 1, original, count)
            count[i] += 1
    return res

        

while True:
    try:
        inp = input()
        count = Counter(inp)
        print(bt(0, inp, count))
    except EOFError:
        break























# from collections import Counter

# def bt(original, index, available):
#     if index == len(original):
#         return 1
#     res = 0
#     for i, j in available.items():
#         if j > 0 and original[index] != i:
#             available[i] -= 1
#             res += bt(original, index + 1, available)
#             available[i] += 1
#     return res

# while True:
#     try:
#         inp = input()
#         count = Counter(inp)
#         print(bt(inp, 0, count))
#     except EOFError:
#         break
