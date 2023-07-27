#relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
#relation = [['a',1,'aaa','c','ng'],['b',1,'bbb','c','g'],['c',1,'aaa','d','ng'],['d',2,'bbb','d','ng']]
#relation = [["a","1","aaa","c","ng"],["a","1","bbb","e","g"],["c","1","aaa","d","ng"],["d","2","bbb","d","ng"]] 
relation = [
    ['a','aa'],
    ['aa','a'],
    ]
from collections import defaultdict
def solution(relation):
    answer = 0
    dic = defaultdict(list)
    for row in relation:
        for i, elem in enumerate(row):
            dic[i].append(elem)

    def _solve(_list):
        nonlocal answer
        def _do_check(cols):
            nonlocal dic
            tmp = []
            for r in range(len(dic[cols[0]])):
                s = ''
                for col in cols: # 1 , 2
                    s += (str(dic[col][r])) + ''
                tmp.append(s)
            before = len(tmp)
            after = len(set(tmp))
            return True if before == after else False
        ret = []
        def _dfs(index, _list, made, until):
            nonlocal ret
            if index == until:
                return
            
            for i, e in enumerate(_list):
                made.append(e)
                ret.append(made[:])
                _dfs(i+1, _list[i+1:], made[:], until)
                made.pop()
        
        _dfs(0,_list,[],len(_list))
        #print("ret : ", ret)
        ret = sorted(ret, key=lambda x: (len(x), x))
        #print(ret)
        visited = [False] * len(ret)
        for i, r in enumerate(ret):
            if visited[i]:
                continue
            #print(r)
            is_same = _do_check(r)
            if is_same:
                answer += 1
                visited[i] = True
                for j in range(i+1, len(ret)):
                    all_exists = True
                    for k in r:
                        if k not in ret[j]:
                            all_exists = False
                            continue
                    if all_exists:
                        visited[j] = True

                    
    _solve([i for i in range(len(dic))])
    return answer 

print(solution(relation))