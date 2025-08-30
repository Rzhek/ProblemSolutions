from collections import defaultdict


last, n = input().split()
n = int(n)
numChars = ord(last) - ord('a') + 1
words = [' ' + input() for _ in range(n)]
graph = defaultdict(list)
indegree = defaultdict(int)

for i in range(1, len(max(words, key=len))):
    for j in range(1, n):
        if words[j-1][i-1] == words[j][i-1] and words[j-1][i] != words[j][i]:
            graph[words[j-1][i]].append(words[j][i])
            indegree[words[j][i]] += 1


for i, j in graph.items():
    print(indegree[i], i, j)
        
