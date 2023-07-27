def getBingoNumber(mat, arr):
    # Write your code here
    x_dic = dict()
    y_dic = dict()
    n = len(mat)
    m = len(mat[0])
    x_counts, y_counts = [0] * n, [0] * m
    for x, row in enumerate(mat):
        for y, val in enumerate(row):
            x_dic[val] = x
            y_dic[val] = y
    for e in arr :
        x, y = x_dic[e], y_dic[e]
        x_counts[x] += 1
        y_counts[y] += 1
        if x_counts[x] == m or y_counts[y] == n :
            return e




print(getBingoNumber([[1,6], [2,4],[5,3]],[2,4,3,1,5,6]))