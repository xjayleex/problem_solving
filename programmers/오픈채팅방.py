records = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

def solution(records):
    answer = []
    dic = dict()
    l = []
    for record in records:
        split = record.split()
        verb, uid = split[0], split[1]
        if verb == 'Enter':
            if uid in dic:
                if dic[uid] != split[2]:
                    dic[uid] = split[2]
            else:
                dic[uid] = split[2]
            l.append(('Enter', uid))
        elif verb == 'Leave':
            l.append(('Leave', uid))
        else: # split[0] == 'Change'
            dic[uid] = split[2]

    for t in l:
        s = dic[t[1]]
        if t[0] == 'Enter':
            s += "님이 들어왔습니다."
        else:
            s += "님이 나갔습니다."
        answer.append(s)
    return answer

print(solution(records))