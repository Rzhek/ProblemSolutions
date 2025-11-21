class Node:
    def __init__(self, l, r) -> None:
        self.l = l
        self.r = r
        self.m = (l + r) // 2
        self.val =  0
        if l != r:
            self.left = Node(self.l, self.m)
            self.right = Node(self.m + 1, self.r)
        else:
            self.left = self.right = None
        
    def set(self, arr):
        if self.l == self.r:
            self.val = arr[self.l - 1]
        else:
            self.left.set(arr)
            self.right.set(arr)
            self.val = self.left.val + self.right.val
    
    def query(self, lo, hi):
        # no over
        if hi < self.l or self.r < lo:
            return 0
        
        # total over
        if lo <= self.l <= self.r <= hi:
            return self.val
        
        # partial over
        return self.left.query(lo, hi) + self.right.query(lo, hi)


if __name__ == '__main__':
    n, q = map(int, input().split())
    segTree = Node(1, n)
    arr = list(map(int, input().split()))
    segTree.set(arr)
    
    # print(segTree.val)

    for _ in range(q):
        l, h = map(int, input().split())
        print(segTree.query(l, h))

