from collections import deque
def solution(maps):
    answer = []
    visited = [[False]*len(maps[0]) for _ in range(len(maps))]
    X, Y = len(maps[0]), len(maps)
    def _bfs(x, y):
        c = 0
        nonlocal maps, visited, X, Y
        dx, dy = [1,-1,0,0], [0,0,-1,1]
        q = deque([(x,y)])
        visited[y][x] = True
        while q :
            x, y = q.popleft()
            c += int(maps[y][x])
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if nx < 0 or ny < 0 or nx >= X or ny >= Y or maps[ny][nx] == 'X' or visited[ny][nx] :
                    continue
                visited[ny][nx] = True
                q.append((nx,ny))
        return c

    for y, row in enumerate(maps) :
        for x, v in enumerate(row) :
            if v != 'X' and not visited[y][x]:
                answer.append(_bfs(x,y))

    return sorted(answer) if len(answer) != 0 else [-1]

maps = ["X591X","X1X5X","X231X", "1XXX1"]
maps1 = ["XXX","XXX","XXX"]
print(solution(maps1))