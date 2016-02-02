# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        stack = []
        x = head
        while x:
            stack.append(x.val)
            x = x.next

        print(stack)
        while head and stack:
            y = stack.pop()
            if y != head.val:
                return False
            head = head.next
        return True


n = ListNode(1)
n.next = ListNode(0)
n.next.next = ListNode(1)
s = Solution()
print(s.isPalindrome(n))
