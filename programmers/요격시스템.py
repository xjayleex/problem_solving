# TODO: Notion 
targets = [[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]]
from collections import deque
def solution(targets):
    answer = 0
    targets = sorted(targets)
    targets = deque(targets)
    while len(targets) :
        s, e = targets.popleft()
        while len(targets) and targets[0][0] < e:
            pop = targets.popleft()
            s, e = max(s, pop[0]), min(e, pop[1])
        answer += 1
    return answer

print(solution(targets))