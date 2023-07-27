'''
def solution(sequence):
    answer = 0
    pattern = [1, -1]
    first = [ e * pattern[i%2] for i, e in enumerate(sequence)]
    second = [ e * pattern[(i+1)%2] for i, e in enumerate(sequence)]
    def _solution(sequence):
        s = sequence[0]
        m = sequence[0]
        for next in sequence[1:]:
            if s <= 0 :
                if next > 0 :
                    s = next
                else :
                    s = s if s >= next else next
            else :
                if next >= 0 :
                    s += next
                else :
                    if s + next >= 0 :
                        s += next
                    else :
                        s = next
        
            m = max(m,s)
        return m
    
    a = _solution(first)
    b = _solution(second)
                
    return a if a > b else b
'''

def solution(sequence):

    # 1 부터 연속펄스 부분 수열을 곱한값 찾기 prefix sum 만들기 
    # maxV - minV 
    # 각각의 리스트에서 max()
    answer = 0
    prefixS = [0]
    for i in range(len(sequence)):
        pulse = 1 if i%2 ==0  else -1
        prefixS.append(prefixS[-1]+pulse*sequence[i])
        print(prefixS)


    return abs(max(prefixS) - min(prefixS))
sequence = [2, 3, -6, 1, 3, -1, 2, 4]
print(solution(sequence))