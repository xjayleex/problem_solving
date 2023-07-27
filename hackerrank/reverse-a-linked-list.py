# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
def reverse(llist):
    root = SinglyLinkedListNode(0)
    root_pointer = root
    ll_pointer = llist
    def _go(ll_pointer, i):
        nonlocal root_pointer
        if ll_pointer.next is not None:
            print(ll_pointer.data)
            _go(ll_pointer.next, i+1)
        root_pointer.data = ll_pointer.data
        if i == 0 :
            return
        root_pointer.next = SinglyLinkedListNode(0)
        root_pointer = root_pointer.next
    _go(ll_pointer, 0)
    return root
