'''
def solution(sequence, k):
    a, b = 0, len(sequence)
    min_len = b - a 
    start, end = 0, -1
    l, part_sum = len(sequence), 0
    while end < l :
        if part_sum == k :
            tmp_len = (end) - start 
            print(start,end)
            if tmp_len < min_len :
                min_len = tmp_len
                a, b = start, end
            part_sum = sequence[end]
            if start == end :
                start, end = end+1, end+1
            else :
                start, end = end, end
        elif part_sum < k :
            end += 1
            if end == l :
                break
            part_sum += sequence[end]
        else : # part_sum > k
            part_sum -= sequence[start]
            start += 1
    return [a,b]
'''
def solution(sequence, k):
    l, r, a, b = 0, 0, 0, 0
    N = len(sequence)
    min = 10000001
    part_sum = sequence[0]
    while True :
        if part_sum == k :
            t = r - l
            if t < min :
                min = t
                a, b = l , r
        if l == N and r == N :
            break
        if part_sum <= k and r < N :
            r += 1
            if r < N :
                part_sum += sequence[r]
        else :
            part_sum -= sequence[l]
            l += 1
    return [a,b]


sequence = [1, 2, 3, 4, 5]
k = 7
sequence1 = [1, 1, 1, 2, 3, 4, 5]
k1 = 5
print(solution(sequence1, k1))
'''
1 | < k
1 2 | < k
1 2 3 | < k
1 2 3 (4) | > k
2 3 | < k
2 3 (4) | > k
3 
3 4 == k'''