# TODO
def extraLongFactorials(n):
    # Write your code here
    from collections import deque
    l = deque()
    l.append(1)
    def _m_digit(t, j):
        nonlocal l
        t0, t1 = 0, 0
        for i, e in enumerate(l):
            t0 = t1
            x = e * t
            d, m = divmod(x,10)
            x = m
            t1 = d
            if x + t0 >= 10 :
                t1 += 1
                x = x + t0 - 10
            else :
                x += t0
            if len(l) == i+j:
                l.append(0)
            l[i+j] = x

    def _multiply(xx):
        xs = str(xx)
        for i in range(len(xs)):
            _m_digit(xs[len(xs)-1-i], i)
            
    for xx in range(2, n+1):
        _multiply(xx)