from collections import deque
def solution(cap, n, deliveries, pickups):
    answer = 0
    l1 = [[i,e] for i, e in enumerate(deliveries) if e != 0]
    l2 = [[i,e] for i, e in enumerate(pickups) if e != 0]
    s1, s2 = deque(l1), deque(l2)
    while s1 or s2 :
        capacity = cap
        d = 0
        if s1 and s2:
            d = s1[-1][0] if s1[-1][0] >= s2[-1][0] else s2[-1][0]
            while s1 and capacity :
                if capacity >= s1[-1][1]:
                    capacity -= s1[-1][1]
                    s1.pop()
                else:
                    s1[-1][1] -= capacity
                    capacity = 0
            capacity = cap
            while s2 and capacity :
                if capacity >= s2[-1][1]:
                    capacity -= s2[-1][1]
                    s2.pop()
                else:
                    s2[-1][1] -= capacity
                    capacity = 0

        elif not s1:
            d = s2[-1][0]
            while s2 and capacity :
                if capacity >= s2[-1][1]:
                    capacity -= s2[-1][1]
                    s2.pop()
                else:
                    s2[-1][1] -= capacity
                    capacity = 0
        else:
            d = s1[-1][0]
            while s1 and capacity :
                if capacity >= s1[-1][1]:
                    capacity -= s1[-1][1]
                    s1.pop()
                else:
                    s1[-1][1] -= capacity
                    capacity = 0
        answer += (d+1) * 2                               
    return answer

print(solution(4,5,[1,0,3,1,2],[0,3,0,4,0]))
print(solution(2,7,[1, 0, 2, 0, 1, 0, 2],[0, 2, 0, 1, 0, 2, 0]))