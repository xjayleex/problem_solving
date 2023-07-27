# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from collections import deque
from typing import Optional

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        answer = None
        pointer = None
        stack = deque()
        while head is not None :
            if len(stack) + 1 == k :
                if answer is None :
                    answer = ListNode(head.val, None)
                    pointer = answer
                else:
                    pointer.next = ListNode(head.val , None)
                    pointer = pointer.next
                while len(stack) != 0:
                    e = stack.pop()
                    pointer.next = ListNode(e, None)
                    pointer = pointer.next
            else :
                stack.append(head.val)
            head = head.next
        
        while len(stack) != 0 :
            e = stack.popleft()
            pointer.next = ListNode(e, None)
            pointer = pointer.next
        #while answer is not None:
        #    print(answer.val)
        #    answer = answer.next
        return answer

node7 = ListNode(7)
node6 = ListNode(6, node7)
node5 = ListNode(5, node6)
node4 = ListNode(4, node5)
node3 = ListNode(3, node4)
node2 = ListNode(2, node3)
node1 = ListNode(1, node2)

# head 노드를 설정합니다.
head = node1

            
solution = Solution()
print(solution.reverseKGroup(head, 2))