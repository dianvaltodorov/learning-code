# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

res = []
class Solution:

    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        Solution.invert_util(root)
        return Solution.inorder(root)

    @classmethod
    def invert_util(cls, root):
        if not root:
            return

        Solution.invert_util(root.right)
        Solution.invert_util(root.left)

        temp = root.left
        root.left = root.right
        root.right = temp

    @classmethod
    def inorder(cls, root):
        left = Solution.inorder(root.left) if root.left else []
        right = Solution.inorder(root.right) if root.left else []
        return left + [root.val] + right

#    1
#   / \
#  2  10
# / \ / \
# 8 9 43 19
t = TreeNode(1)
t.left = TreeNode(2)
t.left.right = TreeNode(9)
t.left.left = TreeNode(8)
t.right = TreeNode(10)
t.right.left = TreeNode(43)
t.right.right = TreeNode(19)

s = Solution()
print(Solution.inorder(t))
s.invertTree(t)
print()
