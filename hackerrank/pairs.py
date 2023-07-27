
def pairs(k, arr):
    # Write your code here
    s = set(arr)
    c = 0
    for elem in arr:
        if elem -k  in s:
            c += 1
    return c

print(pairs(2, [1,5,3,4,2]))