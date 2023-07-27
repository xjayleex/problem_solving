#relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
relation = [
    ['a','aa'],
    ['aa','a'],
    ]
from itertools import combinations

def solution(relation):
    row = len(relation)
    col = len(relation[0])

    #가능한 속성의 모든 인덱스 조합 
    combi = []
    for i in range(1, col+1):
        combi.extend(combinations(range(col), i))
    #유일성
    unique = []
    for i in combi:
        tmp = [tuple([item[key] for key in i]) for item in relation]

        if len(set(tmp)) == row:    # 유일성
            put = True
            
            for x in unique:
                print(x, i)
                if set(x).issubset(set(i)):  # 최소성
                    put = False
                    break
                    
            if put: unique.append(i)
   
    return len(unique)
print(solution(relation))