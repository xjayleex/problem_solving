from collections import defaultdict
def sockMerchant(n, ar):
    # Write your code here
    d = defaultdict(int)
    for a in ar:
        d[a] += 1
    c = 0
    for k in d.keys():
        c = c+ d[k]//2
    return c
