from collections import deque, defaultdict
from pprint import pprint

class Node:
    def __init__(self, val = '', next = [], prev = None, auto = None):
        self.val = val
        self.next = next
        self.prev = prev
        self.auto = auto
    
    def __repr__(self):
        return self.construct()

    def construct(self):
        if self.prev:
            return self.prev.construct() + self.val
        return ''


n, m = map(int, input().split())
start = Node()
count = 0
for _ in range(n):
    word = input()
    cur = start
    prev = start
    nodes = []
    for char in word:
        print(char)
        if not char.isalpha(): continue
        for n in cur.next:
            if n.val == char:
                cur = n
                break
        else:
            count += 1
            newNode = Node(char, [], cur, None)
            nodes.append(newNode)
            cur.next.append(newNode)
        
            cur = newNode
    
    final = nodes.pop()
    for n in nodes:
        if not n.auto:
            n.auto = final
 
# e = start.next[1].next[0].next[0].next[0].next[0].next[0].next[0].next[0]
# print('val:', e.construct())
# print('prev:', e.prev.construct() if e.prev else None)
# print('num of children:', len(e.next))
# print('children:', list(map(lambda x: x.val, e.next)))
# print('autocorrect to:', e.auto.construct() if e.auto else None)
# print(count)

memo = defaultdict(lambda: float('inf'))
for _ in range(m):
    q = deque()
    q.append((start, 0))
    count = 0
    while q:
        for __ in range(len(q)):
            u, w = q.popleft()
            for v in u.next:
                word = v.construct()
                if memo[word] and memo[word] > w + 1:
                    q.append((v, w + 1))
                    memo[word] = w + 1

            if u.prev and memo[u.prev] > w + 1:
                q.append((u.prev, w + 1))
                memo[u.prev.construct()] = w + 1
            
            if u.auto and memo[u.auto] > w + 1:
                q.append((u.auto, w + 1))
                memo[u.auto.construct()] = w + 1

    
print('autocorre' in memo)
for _ in range(m):
    word = input()
    count = 0
    remainder = ''
    while word not in memo and len(word) > 0:
        word = word[:len(word)-1]
        print(word)
        remainder += remainder
        count += 1

    print(count + memo[word])