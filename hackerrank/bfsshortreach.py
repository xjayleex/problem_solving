
def bfs(n, m, edges, s):
    # Write your code here
    adj = [[] for _ in range(n)]
    for edge in edges:
        adj[edge[0]-1].append(edge[1]-1)
        adj[edge[1]-1].append(edge[0]-1)
    visited = [False] * n
    dist = [0] * n
    from collections import deque
    q = deque()
    q.append((s-1,0))
    while len(q) :
        x, d = q.popleft()
        if visited[x]:
            continue
        visited[x] = True
        dist[x] = d
        for y in adj[x]:
            if visited[y]:
                continue
            q.append((y, d+1))
    r = []
    for i in range(n):
        if i == s-1:
            continue
        if visited[i] :
            r.append(6 * dist[i])
        else:
            r.append(-1)
    return r
print(bfs(4,2,[[1,2],[1,3]],1))