
from collections import deque
def waiter(A, q):
    # Write your code here
    is_prime = [True] * 10000
    is_prime[0], is_prime[1] = False, False
    for i in range(2, 10000):
        for j in range(i+i, 10000, i):
            if is_prime[j] :
                is_prime[j] = False
    primes = [0] * (q)            
    c, i = 0, 0
    while c < q :
        while not is_prime[i]:
            i += 1
        primes[c] = i
        c, i = c+1, i+1
    B = deque()
    Q = deque()
    f = [False] * len(A)
    turn = False
    for prime in primes:
        for k, target in enumerate(A):
            if f[k]:
                continue
            if target % prime == 0:
                f[k] = True
                B.append(target)
                #Q.append(target)
        while len(B) :
            if turn : 
                Q.append(B.pop())
            else :
                Q.append(B.popleft())
        turn = not turn
    for k in range(len(A)):
        if not f[k] :
            B.append(A[k])
    while len(B):
        if not turn : 
            Q.append(B.pop())
        else :
            Q.append(B.popleft())
    return list(Q)

# 3 3 4 4 9

# 9 4 4 3 3
# mod 2
# B <- 4, 4 -> Q 
# Q = [4, 4]
# 9 x x 3 3
# B <- 9, 3, 3


print(waiter([3,3,4,4,9],2))