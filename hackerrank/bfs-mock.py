from collections import deque
def bfs(n, m, edges, s):
    # Write your code here
    lens = [0] * n
    visited = [False] * n
    out = []
    adj = [ [] for _ in range(n)] 
    s = s-1
    for edge in edges:
        adj[edge[0]-1].append(edge[1]-1)
        adj[edge[1]-1].append(edge[0]-1)
    q = deque()
    q.append((s, 0))
    while len(q) > 0 :
        # pop q
        point, count = q.popleft()
        if visited[point] :
            continue
        visited[point] = True
        lens[point] = count
        for node in adj[point]:
            if visited[node]:
                continue
            q.append((node, count+1))
    for i in range(n) :
        if i == s:
            continue
        if not visited[i]:
            out.append(-1)
        else:
            out.append(lens[i] * 6)
    return out

def bfs2(n, m, edges, s):
    # Write your code here
    lens = [0] * n
    visited = [False] * n
    out = []
    adj = [ [] for _ in range(n)] 
    s = s-1
    for edge in edges:
        adj[edge[0]-1].append(edge[1]-1)
        adj[edge[1]-1].append(edge[0]-1)
    q = deque()
    q.append((s, 0))
    visited[s] = True
    while len(q) > 0 :
        # pop q
        point, count = q.popleft()
        lens[point] = count
        for node in adj[point]:
            if visited[node]:
                continue
            visited[node] = True
            q.append((node, count+1))
    for i in range(n) :
        if i == s:
            continue
        if not visited[i]:
            out.append(-1)
        else:
            out.append(lens[i] * 6)
    return out

print(bfs(5, 3, [[1,2],[1,3],[3,4]], 1))


    