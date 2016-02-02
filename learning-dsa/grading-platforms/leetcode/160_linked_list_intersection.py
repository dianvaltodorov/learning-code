class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        c1 = self.get_count(headA)
        c2 = self.get_count(headB)
        d = abs(c1 - c2)

        if c1 > c2:
            for _ in range(d):
                headA = headA.next
        else:
            for _ in range(d):
                headB = headB.next

        while headA and headB and headA.val != headB.val:
            headA = headA.next
            headB = headB.next

        if headA and headB:
            return headA

    def get_count(self, head):
        length = 0
        while head:
            head = head.next
            length += 1
        return length
