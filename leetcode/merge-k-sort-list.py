# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import List, Optional
from heapq import heappop,heappush
class Solution:
    def mergeKLists(self, ll_lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        answer = None
        pointer = None
        counter = len(ll_lists)
        for i, head in enumerate(ll_lists):
            if head is None :
                counter -= 1
                continue
            heappush(heap, (head.val,i))
            #print("pushing ... : ", head.val)
            ll_lists[i] = head.next
            #if ll_lists[i] is None :
            #    counter -= 1
            #    print("Poping ", i, " list", "counter :", counter)
                #ll_lists.pop(i)
        if len(heap) == 0 :
            return None
        


        while counter > 0 :
            n, i = heappop(heap)
            if ll_lists[i] is None :
                counter -= 1
                #print("Poping ", i, " list", "counter :", counter)
                # ll_lists.pop(i)
            else:
                e = ll_lists[i]
                ll_lists[i] = ll_lists[i].next
                heappush(heap, (e.val, i))
            if answer is None :
                answer = ListNode(n, None)
                pointer = answer
            else :
                pointer.next = ListNode(n, None)
                pointer = pointer.next

        while len(heap) > 0 :
            n, i = heappop(heap)
            if answer is None :
                answer = ListNode(n, None)
                pointer = answer
            else :
                pointer.next = ListNode(n, None)
                pointer = pointer.next
        #test_pointer = answer
        #while test_pointer is not None :
        #    print(test_pointer.val)
        #    test_pointer = test_pointer.next
        return answer

        

        



node1_3 = ListNode(5, None)
node1_2 = ListNode(4, node1_3)
node1_1 = ListNode(1, node1_2)
head1 = node1_1
        
#node2_3 = ListNode(4, None)
#node2_2 = ListNode(3, node2_3)
node2_1 = ListNode(-2, None)
head2 = node2_1

node3_3 = ListNode(1,None)
node3_2 = ListNode(-2, node3_3)
node3_1 = ListNode(-3, node3_2)
head3 = node3_1

sol = Solution()
r = sol.mergeKLists([None,head2,head3])