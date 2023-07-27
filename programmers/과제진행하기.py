from collections import deque
def solution(plans):
    answer = []
    ordered = []
    start_dict = dict()
    left_dict = dict()
    for plan in plans :
        h,m = plan[1].split(':')
        t = (plan[0], int(h) * 60 + int(m), int(plan[2]))
        ordered.append(t[1])
        start_dict[t[1]] = t[0]
        left_dict[t[1]] = t[2]
    #ordered.sort(key=lambda _: (_[1],_[2]))
    ordered.sort()
    #print(left_dict)
    #print(start_dict)
    #print(ordered)
    paused = deque()
    now = ordered[0]
    for next in ordered[1:]:
        expected = now + left_dict[now]
        #print(expected,next)
        if expected > next :
            left = expected - next
            paused.append(now)
            left_dict[now] = left
        elif expected == next:
            answer.append(now)
        else : # expected < next
            answer.append(now)
            residual = next - expected
            while len(paused) and residual  :
                if left_dict[paused[-1]] <= residual :
                    residual -= left_dict[paused[-1]]
                    left_dict[paused[-1]] = 0
                    did = paused.pop()
                    answer.append(did)
                else :
                    left_dict[paused[-1]] -= residual
                    residual = 0
        now = next
    answer.append(ordered[-1])
    while len(paused) :
        answer.append(paused.pop())

    return [start_dict[e] for e in answer]

plans = [["korean", "11:40", "30"], ["english", "12:10", "20"], ["math", "12:30", "40"]]
plans1 = [["science", "12:40", "50"], ["music", "12:20", "40"], ["history", "14:00", "30"], ["computer", "12:30", "100"]]
print(solution(plans1))