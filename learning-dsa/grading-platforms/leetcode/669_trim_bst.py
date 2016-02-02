# Definition for a binary tree node.
class TreeNode:
    def __init__(self,):
        self.val = None
        self.left = None
        self.right = None


class Solution:
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """

    @staticmethod
    def trim_util(root, L, R):

        if not root:
            return

        if root.val < L:
            root.left = Solution.trim_util(root.left, L, R)

        if root.val > R:
            root.right = Solution.trim_util(root.left, L, R)

        if root.val < L:
            Solution.trim_util(root.left, L, R)
            Solution.trim_util(root.right, L, R)

        return node

#    3
#   / \
#  9  20
#    /  \
#   15   7
#  /  \
# 1    18
#

root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
root.right.left.right = TreeNode(18)
root.right.left.left = TreeNode(1)

s = Solution()
print(s.trimBST())
