def solution_time_overflow(r1, r2):
    answer = 0
    on_line = r2 - r1 + 1
    r1r1 = r1*r1
    r2r2 = r2*r2
    for x in range (1, r2+1):
        for y in range (1, r2+1):
            l = x*x + y*y
            if l < r1r1 :
                continue
            if l > r2r2 :
                break
            answer += 1
    answer = (answer + on_line) * 4

    return answer
from math import floor, ceil, sqrt
def solution(r1, r2):
    answer = 0
    for x in range(1, r2+1):
        max_y = floor(sqrt(r2*r2 - x*x))
        min_y = ceil(sqrt(r1*r1 - x*x)) if r1 > x else 0
        answer += max_y - min_y + 1
    return answer*4


print(solution(2,3))