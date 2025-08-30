# import sys


# n = int(input())
# seq = []
# last = None
# count = 0
# for i in range(n):
#     curr = int(input())
#     if last is None:
#         last = curr
#     if last == curr:
#         count += 1
#     else:
#         seq.append((last, count))
#         last = curr
#         count = 1
# else:
#     seq.append((curr, count))

# sys.setrecursionlimit(len(seq) + 10)

# def solve(index, currTool, tools):
#     if index >= len(seq): 
#         return 0
#     if currTool == seq[index][0]:
#         return seq[index][1] + solve(index + 1, currTool, tools)
    
#     temp = solve(index + 1, currTool, tools)
#     if seq[index][0] in tools:
#         temp = max(temp, seq[index][1] + solve(index + 1, seq[index][0], tools.difference({seq[index][0]})))
#     return temp

# print(max(
#     solve(0, 0, {1, 2}),
#     solve(0, 1, {0, 2}),
#     solve(0, 2, {0, 1}),
# ))

# # !/bin/python3

# import itertools

# states = []
# for k in range(4): states += itertools.permutations((0,1,2), k)

# memo = {s:0 for s in states}

# n = int(input())
# tasks = []
# for _ in range(n):
#     tasks.append(int(input()))
# for x in tasks[::-1]:
#     nxt = {s:0 for s in states}
#     for tools in states:
#         if not tools: nxt[tools] = memo[tools]
#         elif x == tools[-1]: nxt[tools] = 1 + memo[tools]
#         else: nxt[tools] = max(nxt[tools[:-1]], memo[tools])
#     memo = nxt

# print(max(memo.values()))
