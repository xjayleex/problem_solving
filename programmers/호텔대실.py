from heapq import heappush, heappop
def solution(book_time):
    cnt = 0
    trans = []
    for time in book_time :
        a, b = time[0].split(":")
        s = int(a) * 60 + int(b)
        a, b = time[1].split(":")
        e = int(a) * 60 + int(b) + 10
        trans.append([s,e])
    trans.sort(key=lambda _:(_[0], _[1]))
    '''
    pq, cnt = [(trans[0][1], trans[0][0])], 1 # pq elem => (end, start, numbering with cnt)
    for book in trans[1:] :
        if pq[0][0] > book[0] :
            heappush(pq, (book[1],book[0]))
            cnt += 1
        else :
            top = heappop(pq)
            heappush(pq, (book[1],book[0]))
    '''
    pq, cnt = [trans[0][1]], 1 # pq elem => (end, start, numbering with cnt)
    for book in trans[1:] :
        if pq[0] > book[0] :
            heappush(pq, book[1])
            cnt += 1
        else :
            top = heappop(pq)
            heappush(pq, book[1])

    return cnt

book_time = [["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]
print(solution(book_time))