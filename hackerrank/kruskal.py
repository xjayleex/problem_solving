def kruskals(g_nodes, g_from, g_to, g_weight):
    # Write your code here
    g = list(zip(g_from,g_to,g_weight))
    g.sort(key=lambda x:x[2])
    adj = [[] for _ in range(g_nodes)]
    parent = [i for i in range(g_nodes)] 

    cost = 0
    def union(x,y,w):
        nonlocal parent
        nonlocal cost
        x = find_root(x)
        y = find_root(y)
        if x == y:
            return
        parent[y] = x
        cost += w
    def find_root(x):
        nonlocal parent
        if parent[x] == x:
            return x
        return find_root(parent[x])
    for a,b, w in g:
        if a > b:
            t = a
            a = b
            b = t
        union(a-1,b-1,w)
    return cost


print(kruskals(4, [1,1,4,2,3,3], [2,3,1,4,2,4], [5,3,6,7,4,5]))
