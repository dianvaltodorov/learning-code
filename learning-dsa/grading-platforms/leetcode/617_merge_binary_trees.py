class TreeNode:

    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


r1 = TreeNode(1)
r1.left = TreeNode(2)
r1.right = TreeNode(10)
r1.left.left = TreeNode(4)
r1.left.left.left = TreeNode(4)

r2 = TreeNode(1)
r2.left = TreeNode(2)
r2.right = TreeNode(10)
r2.right.left = TreeNode(4)
r2.right.left.left = TreeNode(4)


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1:
            return t2
        if not t2:
            return t1
        r = TreeNode(t1.val + t2.val)
        r.left = self.mergeTrees(t1.left, t2.left)
        r.right = self.mergeTrees(t1.right, t2.right)
        return r


s = Solution()
r = s.mergeTrees(r1, r2)
print(r)
