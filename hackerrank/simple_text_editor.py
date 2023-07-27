from collections import deque
def scan():
    c = int(input().strip())
    ops = []
    for _ in range(c):
        args = input().strip().split()
        param = None if len(args) == 1 else args[1]
        ops.append((int(args[0]), param))
    return ops

def f():
    s = ''
    op_registry = deque()
    del_registry = deque()
    ops = scan()
    for op in ops:
        t, param = op[0], op[1]
        if t <= 2 :
            op_registry.append(op)

        if t == 1: # append
            s += param
        elif t == 2: # delete
            del_registry.append(s[len(s)-int(param):])
            s = s[:len(s)-int(param)]
        elif t == 4: # undo
            recovered = op_registry.pop()
            if recovered[0] == 1:
                s = s[:len(s)-len(recovered[1])]
            else:
                d = del_registry.pop()
                s += d
        else: 
            print(s[int(param)-1])

f()
