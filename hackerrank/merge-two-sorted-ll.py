# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(head1, head2):
    head = None
    pointer = None
    while head1 is not None or head2 is not None:
        if head is None :
            head = SinglyLinkedListNode(0)
            #tail = SinglyLinkedListNode()
            #head.next = tail
            pointer = head

        if head1 is None:
            while head2 is not None:
                pointer.data = head2.data
                head2 = head2.next
                tail = SinglyLinkedListNode(0) if head2 is not None else None
                pointer.next = tail
                pointer = pointer.next
            break
        if head2 is None:
            while head1 is not None:
                pointer.data = head1.data
                head1 = head1.next
                tail = SinglyLinkedListNode(0) if head1 is not None else None
                pointer.next = tail
                pointer = pointer.next
            break
        if head1.data < head2.data :
            pointer.data = head1.data
            head1 = head1.next
        else :
            pointer.data = head2.data
            head2= head2.next
        new = SinglyLinkedListNode(0) if (head1 is not None or head2 is not None) else None
        pointer.next = new
        pointer = pointer.next
    return head

        

