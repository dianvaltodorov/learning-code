class Node(object):

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


def dfs_util(root, path, target):
    if root is None:
        return False

    path.append(root.data)

    if root.data == target:
        return True

    if root.left and dfs_util(root.right, path, target) or root.right and dfs_util(root.left, path, target):
        return True

    path.pop()


if __name__ == "__main__":
    root = Node(2)
    root.left = Node(3)
    root.right = Node(5)
    root.right.left = Node(17)
    root.right.right = Node(18)
    root.left.left = Node(10)
    root.left.right = Node(100)
    root.left.right.left = Node(30)
    root.left.right.right = Node(67)
    root.left.left.left = Node(40)
    root.left.left.right = Node(87)
    path1 = []
    path2 = []
    dfs_util(root, path1, 67)
    dfs_util(root, path2, 87)
    print path1
    print path2
    i = 0
    while path1[i] == path2[i]:
        i += 1
    print path1[i-1]