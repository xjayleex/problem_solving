def solution(k, scores):
    from heapq import heappush
    from heapq import heappop
    answer = []
    heap = []
    heapfull = lambda h: True if len(h) >= k else False
    for score in scores :
        #print(heapfull(heap))
        if not heapfull(heap) :
            heappush(heap, score)
        else :
            if heap[0] < score :
                heappop(heap)
                heappush(heap,score)
        answer.append(heap[0])
    return answer   

print(solution(3, [10, 100, 20, 150, 1, 100, 200]))