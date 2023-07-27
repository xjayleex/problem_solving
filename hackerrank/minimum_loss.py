def minimumLoss(price):
    # Write your code here
    l = [(p, i) for i, p in enumerate(price)]
    l.sort(key=lambda x:-x[0])
    minima = 10000000000000000
    for i in range(1,len(l)):
        if l[i-1][1] > l[i][1] :
            continue
        diff = l[i-1][0] - l[i][0]
        if diff < minima :
            minima = diff
    return minima
        

print(minimumLoss([20,15,17,11,16]))