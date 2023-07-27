def solution(word):
    d = ['A','E',"I",'O','U']
    count = 0
    found = False
    def _dfs(made, word):
        nonlocal count
        nonlocal d
        nonlocal found
        if len(made) > 5:
            return
        if made == word:   
            print(count)
            found = True
            return 
        for c in d :
            if found or len(made) >= 5 :
                return
            count += 1
            _dfs(made+c, word)

    _dfs('', word)
    answer = count
    return answer

print(solution("I"))
