import heapq


class Node:

    def __init__(self, lo, hi) -> None:
        self.lo = lo
        self.hi = hi
        self.mid = (lo + hi) // 2
        self.val = 0
        self.left = Node(lo, self.mid) if lo != hi else None
        self.right = Node(self.mid + 1, hi) if lo != hi else None
    
    def query(self, l, r):
        if l > self.hi or r < self.lo: 
            return 0
        if (l <= self.lo and self.hi <= r): 
            return self.val
        return self.left.query(l, r) + self.right.query(l, r)
    
    def update(self, i, amount):
        if self.lo == self.hi:
            self.val += amount
            return
        if i < self.mid: 
            self.left.update(i, amount)
        else: 
            self.right.update(i, amount) 
        self.val = self.left.val + self.right.val


for _ in range(int(input())):
    n, q, r = map(int, input().split())
    roles = list(map(int, input().split())) + [n + 1]
    heapq.heapify(roles)

    server = Node(0, n+1)
    for __ in range(q):
        inp = input().split()
        if inp[0] == 'A':
            role, people = map(int, inp[1:])
            server.update(role, people)
        elif inp[0] == 'B':
            role, people = map(int, inp[1:])
            server.update(role, -people)
        elif inp[0] == 'C':
            heapq.heappush(roles, (int(inp[1])))
        elif inp[0] == 'D':
            roles.remove(int(inp[1]))
            heapq.heapify(roles)

        print(server.query(0, roles[0]) + 1)
        # role = heapq.heappop(roles)
        # heapq.heappush(role)
