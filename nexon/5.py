from heapq import heappop, heappush
def bestSumKStar(g_nodes, g_from, g_to, values,k):
    heaps = [[] for _ in range(g_nodes)]
    for fr, to in zip(g_from, g_to):
        heappush(heaps[fr-1], -values[to-1])
        heappush(heaps[to-1], -values[fr-1])
    print(heaps)
    a = [10000000] * g_nodes
    exists = [False if len(heaps[i]) < k else True for i in range(g_nodes)] 
    for i in range(g_nodes) :
        if not exists[i] :
            continue
        s, kk = 0, k
        while kk :
            kk -= 1
            s += heappop(heaps[i])
        a[i] = s - values[i]
    return -min(a)

g_nodes = 5
g_from =[3,3,3,3]
g_to = [1,2,4,5]
values = [10,20,30,40,50]
k = 2
print(bestSumKStar(g_nodes, g_from, g_to, values, k))
g_nodes = 7
g_from =[0,1,1,3,3,3]
g_to = [1,2,3,4,5,6]
values = [1,2,3,4,10,-10,-20]
k = 2
print(bestSumKStar(g_nodes, g_from, g_to, values, k))