expression = "100-200*300-500+20"
# expression = [100,-,200,*,300,-,500,+, 20]
# 100
# 100 -
# 100 - 200
## encounter *, pop from stack, 
def solution(expression):
    def _solution(l, ops_seq): # return absolute value
        for ops in ops_seq:
            stack = []
            while len(l) != 0:
                c = l.pop(0)
                if c == ops :
                    stack.append(operation(stack.pop(), l.pop(0), ops))
                else :
                    stack.append(c)
            l = stack
        return abs(int(stack[0]))

    answer = 0
    ops_perm = perm()
    tmp = ""
    l = []
    for c in expression:
        if c.isdigit():
            tmp += c
        else:
            l.append(tmp)
            l.append(c)
            tmp = ""
    l.append(tmp)
    for ops_seq in ops_perm:
        answer = max(answer, _solution(l[:], ops_seq))

    return answer

def operation(num1, num2, op):
    if op == '+':
        return str(int(num1) + int(num2))
    if op == '-':
        return str(int(num1) - int(num2))
    if op == '*':
        return str(int(num1) * int(num2))
    
def perm():
    l = ['+','-','*']
    ret = []
    def _dfs(ops, depth, li , length):
        nonlocal ret
        if depth == length:
            ret.append(ops)
            return 
        for i, e in enumerate(li):
            lli = li[:i] + li[i+1:]
            ops.append(e)
            _dfs(ops[:], depth+1, lli, length)
            ops.pop()

    _dfs([], 0, l, len(l))

    return ret

print(solution(expression=expression))