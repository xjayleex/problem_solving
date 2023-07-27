def balancedSums(arr):
    # Write your code here
    if len(arr) == 1:
        print("YES")
        return
    s = sum(arr)
    left = 0
    for i, e in enumerate(arr):
        s = s - e
        if s == left :
            print("YES")
        left += e
    print("NO")

balancedSums([1,2,3,3])