from collections import deque
def solution(picks, minerals):
    answer = 0
#    for i, e in enumerate(minerals):
    capacity = sum(picks) * 5
    minerals = minerals[:capacity]
    m = {'d':0, 'i':1, 's':2}
    compare = lambda x : (-x[0],-x[1],-x[2])
    l = []
    for i in range(0, len(minerals), 5):
        d = [0,0,0]
        for e in minerals[i:i+5]:
            d[m[e[0]]] += 1
        l.append(d)
    l = deque(sorted(l, key=compare))
    i = 0
    while True :
        if i == 3 or not len(l):
            break
        if picks[i] == 0 :
            i += 1
       # if i == 3 or not len(l):
       #     break
        picks[i] -= 1
        targets = l.popleft()
        cost = 0
        if i == 0:
            cost = targets[0] + targets[1] + targets[2]
        elif i == 1:
            cost = 5*targets[0] + targets[1] + targets[2]
        else :
            cost = 25*targets[0] + 5*targets[1]  + targets[2]
        answer += cost

    return answer
# d / i / s
picks = [1,1,0]
minerals = ["stone", "stone", "iron", "stone", "diamond", "diamond", "diamond", "diamond", "diamond", "diamond"]
print(solution(picks, minerals))