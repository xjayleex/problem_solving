number = "4177252841"
from collections import deque
def solution(number, k):
    stack = deque()
    for n in number:
        while len(stack) > 0 and k > 0 and stack[-1] < n:
            stack.pop()
            k -= 1
        stack.append(n)
    l = [e for e in stack][:len(stack)-k]
    answer = ''.join(l)
    return answer

print(solution("4321",1))