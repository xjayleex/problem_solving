
import math
import os
import random
import re
import sys

#
# Complete the 'roadsAndLibraries' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER c_lib
#  3. INTEGER c_road
#  4. 2D_INTEGER_ARRAY cities
#

def roadsAndLibraries(n, c_lib, c_road, cities):
    # Write your code here
    visited = [False] * n
    adj = [[] for _ in range(n)]
    for city in cities:
        adj[city[0]-1].append(city[1]-1)
        adj[city[1]-1].append(city[0]-1)
    counts = dict()
    def _dfs(src, mark):
        nonlocal visited
        nonlocal adj
        visited[src] = True
        for conn in adj[src]:
            if visited[conn]:
                continue
            counts[mark] += 1
            _dfs(conn, mark)

    for i in range(n):
        if visited[i] is True:
            continue
        counts[i] = 0
        _dfs(i, i)
    
    summ = 0 
    for k in counts:
        edges = counts[k]
        print(min(edges * c_road + c_lib, (edges+1) * c_lib ))
        summ += min(edges * c_road + c_lib, (edges+1) * c_lib )
    return summ
    

print(roadsAndLibraries(6,2,5,[]))