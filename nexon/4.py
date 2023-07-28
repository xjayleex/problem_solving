def getkthSmallestTerm(arr, k):
    from itertools import product
    
    r = list(product(arr, repeat=2))
    r.sort()
    return [r[k-1][0], r[k-1][1]]


print(getkthSmallestTerm([2,2,1], 5))