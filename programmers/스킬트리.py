skill = "CBD"
skill_trees = ["BACDE", "CBADF", "AECB", "BDA"]
def solution(skill, skill_trees):
    answer = 0
    prev = dict()
    for i, s in enumerate(skill[1:], 1):
        prev[s] = skill[i-1]

    for skill_tree in skill_trees:
        skilled = set()
        succeed = True
        for c in skill_tree:
            if c not in prev.keys():
                skilled.add(c)
            else:
                if prev[c] not in skilled:
                    succeed = False
                    break
                else:
                    skilled.add(c)
        answer += 1 if succeed else 0
            
    return answer

print(solution(skill, skill_trees))