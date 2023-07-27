def countingSort(arr):
    # Write your code here
    from collections import defaultdict
    d = defaultdict(int)
    for a in arr:
        d[a] += 1
    r = [d[i] for i in range(100)]
    return r

print(countingSort([63,25,73,1,98,73,56,84,86,57,16,83,8,2,8,56,9]))




