from heapq import *
def isValid(s):
    def _is_all_same(l):
        prev = l[0]
        for e in l[1:]:
            if prev != e :
                return False
        return True
    # Write your code here
    counts = [0] * 26
    for c in s:
        counts[ord(c) - 97] += 1
    sortedlist = []
    S = set()
    for i, count in enumerate(counts):
        if count == 0:
            continue
        sortedlist.append(count)
        S.add(count)
    sortedlist.sort()
    if len(S) == 1 :
        return "YES"
    sortedlist[-1] -= 1
    if _is_all_same(sortedlist):
        return "YES"
    sortedlist[-1] += 1
    if sortedlist[0] == 1 :
        heappop(sortedlist)
        if _is_all_same(sortedlist):
            return "YES"
    return "NO"


print(isValid('abcdefghhgfedecba'))