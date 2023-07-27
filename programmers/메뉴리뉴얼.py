#orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
# orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
orders =	["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]
course = [2,3,5]

from collections import defaultdict
def comb_for_orders(orders):
    result = []
    def _comb(order):
        ret = []
        def _dfs(left_chars, leng, made):
            nonlocal ret

            if len(made) > 1:
                ret.append(made)

            if left_chars == '':
                return

            for i, c in enumerate(left_chars):
                made += c
                _dfs(left_chars[i+1:], leng, made)
                made = made[:-1]
       
       
        _dfs(order, len(order),'')
        return ret
    
    for order in orders:
        order = ''.join(sorted(order))
        result.append(_comb(order))
    
    return result



# combination 
def solution(orders, course):
    answer = []
    len_to_menus = defaultdict(list)

    counts_map = defaultdict(int)
    combs = comb_for_orders(orders)
    for comb in combs:
        for menu in comb:
            counts_map[menu] += 1

    print(counts_map)
    for k in counts_map:
        n = counts_map[k]
        if n < 2:
            continue
        _list = len_to_menus[len(k)]
        if len(_list) == 0:
            _list.append((k, n))
        else:
            if n > _list[0][1]:
                _list = [(k,n)]
                len_to_menus[len(k)] = _list
            elif n == _list[0][1]:
                _list.append((k,n))
    for c in course:
        if len_to_menus[c] is not None:
            for e in len_to_menus[c]:
                answer.append(e[0])
    return sorted(answer)

print(solution(orders, course))