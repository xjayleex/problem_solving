from collections import deque
def solution(board):
    answer = -1
    R, G = None, None
    LX, LY = len(board[0]), len(board)
    M = dict()
    DM = {2:0, 0:2, 1:3,3:1}
    def key(_x,_y,_dr) :
        return str(_x) + str(_y) + str(_dr)
    dx, dy, dr = [0,1,0,-1], [-1,0,1,0], [0,1,2,3]
    for y, row in enumerate(board):
        for x, e in enumerate(row):
            if e == 'R':
                R = (x, y)
            elif e == 'G':
                G = (x, y)
    q = deque()
    for i in range(4):
        M[key(R[0],R[1],dr[i])] = True
        nx, ty = R[0]+dx[i], R[1]+dy[i]
        if nx < 0 or nx >= LX or ty < 0 or ty >= LY or board[ty][nx] == 'D':
            continue
        q.append((R[0],R[1],dr[i],0))
    while q :
        x, y, d, c = q.popleft()
        #if board[y][x] is 'G':
        #    answer = c
        #    break
        for k in range(4):
            nx, ny = x, y
            while True:
                tx, ty = nx + dx[k], ny + dy[k]
                if tx < 0 or ty < 0 or tx >= LX or ty >= LY or board[ty][tx] == 'D':
                    break
                nx, ny = tx, ty
            if nx == G[0] and ny == G[1]:
                return c+1
            for nd in range(4):
                if nd == DM[k]:
                    continue
                nkey = key(nx,ny,nd)
                if nkey in M :
                    continue
                else :
                    M[nkey] = True
                q.append((nx, ny, nd, c+1))
    return answer