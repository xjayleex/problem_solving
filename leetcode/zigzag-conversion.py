'''
A . . . . K . . . . U
B . . . J L . . . T V
C . . I . M . . S . W
D . H . . N . R . . X
E G . . . O Q . . . Y  
F . . . . P . . . . Z

(row - 2) * 2 + 2 
'''
from collections import deque
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        answer = ''
        seg = (numRows - 2) * 2 + 2
        split = [s[i:i+seg]for i in range(0, len(s), seg)]

        if len(split[-1]) < seg:
            split[-1] = split[-1] + '0' * (seg - len(split[-1]))

        deqs = [deque(l) for l in split]
        for deq in deqs:
            answer += deq.popleft()
        def _pop(l):
            r = ''
            if len(l) == 0:
                return r
            p = l.popleft()
            if p != '0':
                r += p
            if len(l) == 0:
                return r
            p = l.pop()
            if p != '0':
                r += p
            return r


        while any([len(deq) != 0 for deq in deqs]):
            for deq in deqs:
                answer += _pop(deq)

        return answer


solution = Solution()
print(solution.convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 2))
print(solution.convert("A", 1))
print(solution.convert("PAYPALISHIRING", 3))