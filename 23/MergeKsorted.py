def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

    def merge2Lists(List1, List2):
        if List1 is None and List2 is None:
            return None
        elif List1 is None:
            return List2
        elif List2 is None:
            return List1
        
        curr1 = List1
        curr2 = List2

        head = dummy = ListNode()

        # keep track of curr
        while curr1 and curr2:
            if curr1.val >= curr2.val:
                dummy.next = curr2
                curr2 = curr2.next
            else:
                dummy.next = curr1
                curr1 = curr1.next
            dummy = dummy.next
        
        if curr1:
            dummy.next = curr1
        elif curr2:
            dummy.next = curr2

        return head.next # needed otherwise sets it to ListNode() which is initialized to 0
    
    n = len(lists)
    if n == 0:
        return None
    elif lists[0] == []:
        return None

    result = lists[0]

    for i in range(1, n):
        result = merge2Lists(lists[i], result)
        # curr = result
        # while curr:
        #     print(curr.val)
        #     curr = curr.next

    return result
