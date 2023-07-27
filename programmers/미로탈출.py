from collections import deque
def solution(maps):
    answer =0
    S, E, L = None, None, None
    LX, LY = len(maps[0]), len(maps)
    for y, row in enumerate(maps) :
        for x, e in enumerate(row) :
            if e is 'L':
                L = (x, y)
            elif e is 'S':
                S = (x, y)
            elif e is 'E':
                E = (x, y)
    print(L,S,E)
    LTOS, LTOE = None, None
    def bfs(spoint, epoint) :
        nonlocal maps, LX, LY
        visited = [[0]* LX for _ in range(LY)]
        q = deque([(spoint[0],spoint[1], 0)])
        dx = [1,0,0,-1]
        dy = [0,-1,1,0]
        ret = -1

        while q :
            x, y, c = q.popleft()
            #print(x,y,c)
            if x == epoint[0] and y == epoint[1]:
                ret = c
                break
            for k in range(4):
                nx, ny, nc = x+dx[k], y+dy[k], c+1
                if nx >= LX or ny >= LY or nx < 0 or ny < 0 or maps[ny][nx] is 'X' or visited[ny][nx] :
                    continue
                visited[ny][nx] = nc
                q.append((nx,ny,nc))
        return ret
    LTOS = bfs(L, S)
    LTOE = bfs(L, E)
    answer = LTOS + LTOE if (LTOS > 0 and LTOE > 0) else -1
    return answer