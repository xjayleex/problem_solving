infos = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
queries = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 220","cpp and - and senior and pizza 270","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

def solution(infos, queries):
    answer = [0] * len(queries)
    data = dict()
    for a in ['cpp', 'java', 'python', '-']:
        for b in ['backend', 'frontend', '-']:
            for c in ['junior', 'senior', '-']:
                for d in ['chicken', 'pizza', '-']:
                    data.setdefault((a, b, c, d), list())

    for info in infos:
        sp = info.split()
        for a in [sp[0], '-']:
            for b in [sp[1], '-']:
                for c in [sp[2], '-']:
                    for d in [sp[3], '-']:
                        data[(a,b,c,d)].append(int(sp[4]))

    for k in data:
        data[k].sort()

    for i, q in enumerate(queries):
        sp = q.split()
        pool = data[(sp[0], sp[2], sp[4], sp[6])]
        l, r = 0, len(pool)
        while l < r:
            mid = (l+r) // 2
            if int(sp[7]) <= pool[mid]: # target , find
                r = mid
            else:
                l = mid + 1
        
        print(l,r, pool, sp[7])
        answer[i] = len(pool) - l

    return answer

print(solution(infos,queries))

