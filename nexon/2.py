def getkthSmallestTerm(arr, k):
    from collections import Counter
    arr.sort()
    c = Counter(arr)
    ans = None
    done = False
    print(c.items())
    s = sum(c.values())
    for i, vi in c.items():
        if vi * s < k :
            k = k - vi * s
            continue
        for j, vj in c.items():
            k = k - vi*vj
            if k <= 0 :
                ans = [i,j]
                done = True
                break
        if done :
            break
    return ans

print(getkthSmallestTerm([5,5,10,10,5,8], 4))

    