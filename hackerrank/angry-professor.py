def angryProfessor(k, a):
    # Write your code here
    a.sort()
    if a[k-1] <= 0 :
        return "NO"
    else :
        return "YES"