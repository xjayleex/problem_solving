from collections import deque
def isBalanced(s):
    # Write your code here
    stack = deque()
    lside = set(['{','[','('])
    rside = set(['}',']',')'])
    flag = True
    for c in s:
        if c in lside:
            stack.append(c)
        else:
            if len(stack) == 0 :
                flag = False
                break
            p = stack.pop()
            if (p == '{' and c == '}') or (p == '[' and c==']') or (p=='(' and c == ')'):
                continue
            else:
                flag = False
                break
    if len(stack) > 0 :
        flag = False
    return 'YES' if flag else 'NO'

print(isBalanced('}][}}(}][))]'))
