

class Q:
    def __init__(self):
        from collections import deque
        self.s1 = deque()
        self.s2 = deque()

    def enqueue(self, x):
        self.s1.append(x)

    def dequeue(self):
        if len(self.s2) > 0:
            return self.s2.pop()
        while len(self.s1):
            self.s2.append(self.s1.pop())
        if len(self.s2) > 0:
            return self.s2.pop()
        else :
            return -1
    
    def top(self):
        if len(self.s2) > 0:
            print(self.s2[-1])
        else:
            while len(self.s1):
                self.s2.append(self.s1.pop())
            if len(self.s2) > 0:
                print(self.s2[-1])
            else:
                print(-1)

def solve():
    q = Q()
    c = int(input().strip())
    for _ in range(c):
        args = input().strip().split(' ')
        if args[0] == '1':
            q.enqueue(int(args[1]))
        elif args[0] == '2':
            q.dequeue()
        else:
            q.top()

solve()