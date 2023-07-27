def solution(n, s, a, b, fares):
    inf = 200 * 100000 + 1
    answer = inf
    dist = [[inf] * n for _ in range(n)]
    for f in fares:
        dist[f[0]-1][f[1]-1] = f[2]
        dist[f[1]-1][f[0]-1] = f[2]
    for i in range(n):
        for j in range(n):
            dist[i][j] = 0 if i == j else dist[i][j]
    # do floyd
    for m in range(n):
        for i in range(n):
            if dist[i][m] == inf:
                continue
            for j in range(n):
                if dist[j][m] == inf:
                    continue
                dist[i][j] = min(dist[i][j], dist[i][m] + dist[m][j])
    #print(dist)
    for v in range(n):
        answer = min(answer, dist[s-1][v] + dist[v][a-1] + dist[v][b-1] )
    return answer


fares = [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]
print(solution(6,4,6,2,fares))