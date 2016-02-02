class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

root = TreeNode(1)
root.left = TreeNode(3)
root.right = TreeNode(4)
root.left.right = TreeNode(5)
s = Solution()
print(s.maxDepth(root))