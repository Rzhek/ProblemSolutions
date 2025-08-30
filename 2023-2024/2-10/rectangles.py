import sys

class Node:
    def __init__(self, x1, y1, x2, y2, val = 0):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.val = val * self.getArea()
        self.q1 = self.q2 = self.q3 = self.q4 = None
    
    def getArea(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)
    
    def createNodes(self, val=0):
        x1, y1, x2, y2 = self.x1, self.y1, self.x2, self.y2
        xm, ym = (x1 + self.x2) // 2, (y1 + self.y2) // 2
        self.q1 = Node(x1, y1, xm, ym, val)
        self.q2 = Node(xm, y1, x2, ym, val)
        self.q3 = Node(x1, ym, xm, y2, val)
        self.q4 = Node(xm, ym, x2, y2, val)

    def update(self, x1, y1, x2, y2):
        # print(x1, y1, x2, y2, '|', self.x1, self.y1, self.x2, self.y2,  end=': ')
        # input()
        # No overlap
        if x2 <= self.x1 or self.x2 <= x1 or y2 <= self.y1 or self.y2 <= y1:
            # print('no over')
            return self.val

        # Total overlap
        if x1 <= self.x1 <= self.x2 <= x2 and y1 <= self.y1 <= self.y2 <= y2:
            # print('total over')
            self.val = self.getArea() - self.val
            if self.q1:
                self.q1.update(x1, y1, x2, y2)
                self.q2.update(x1, y1, x2, y2)
                self.q3.update(x1, y1, x2, y2)
                self.q4.update(x1, y1, x2, y2)
            return self.val

        # Partial overlap
        # print('partial over')
        if not self.q1:
            self.createNodes(self.val > 0)
        
        val = 0
        val += self.q1.update(x1, y1, x2, y2)
        val += self.q2.update(x1, y1, x2, y2)
        val += self.q3.update(x1, y1, x2, y2)
        val += self.q4.update(x1, y1, x2, y2)
        self.val = val
        return self.val


# sys.setrecursionlimit(10)
n = int(input())
bound = 10e9
segTree = Node(0, 0, bound, bound)
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    segTree.update(x1, y1, x2, y2)

print(segTree.val)
# segTree.update(0, 0, 5, 5)
# while (input() != '0'):
#     print('-----------------')
# print(segTree.val)
# segTree.update(5, 0, 9, 5)
# print(segTree.val)
# segTree.update(1, 1, 8, 8)
# print(segTree.val)
# print(segTree.q1.val)
# print(segTree.q2.val)
# print(segTree.q3.val)
# print(segTree.q4.val)