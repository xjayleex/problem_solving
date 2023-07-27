def solution(numbers, target):
    answer = 0

    def _dfs(sumation, index, target):
        nonlocal numbers
        nonlocal answer
        if index == len(numbers):
            if sumation == target:
                answer += 1
            return
        _dfs(sumation=sumation-numbers[index], index=index+1, target=target)
        _dfs(sumation=sumation+numbers[index], index=index+1, target=target)

    _dfs(sumation=0, index=0, target = target)
    return answer