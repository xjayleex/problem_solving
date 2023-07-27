def printShortestPath(n, i_start, j_start, i_end, j_end):
    # Print the distance along with the sequence of moves.
    # UL[0] = (-1, -2), UR[1] = (1, -2), R[2] = (2, 0)
    # L[5] = (-2, 0), LL[4] = (-1, 2), LR[3] = (1, 2)
    command_dict = {'0':'UL', '1':'UR', '2':'R', '3':'LR', '4':'LL', '5':'L'}
    dx = [-1,1,2,1,-1,-2]
    dy = [-2,-2,0,2,2,0]
    from collections import deque
    board = [[-1] * n for _ in range(n)]
    visited = [[False ] *n for _ in range(n)]
    board[j_end][i_end] = -2
    q = deque()
    q.append((j_start, i_start, '', 0))
    cmd_count = -1
    command = ''
    while len(q) :
        x, y, cmd, cnt = q.popleft()
        if visited[x][y]:
            continue
        visited[x][y] = True
        if board[x][y] == -2:
            cmd_count = cnt
            command = cmd
            break
        board[x][y] = cnt 
        for k in range(6):
            nx, ny = x + dx[k], y + dy[k]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            #if board[nx][ny] != -1 and board[nx][ny] != -2:
            #    continue
            if visited[nx][ny] :
                continue
            q.append((nx,ny, cmd + str(k), cnt + 1))
    if cmd_count == -1 :
        print("Impossible")
    else :
        print(cmd_count)
        for c in command:
            print(command_dict[c], end=' ')




printShortestPath(50,40,35,1,4)