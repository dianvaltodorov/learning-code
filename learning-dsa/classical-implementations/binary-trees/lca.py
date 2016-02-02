"""LCA"""

class Node(object):
    """Holds a binary tree node"""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def find_path(root, path, data):
    """Return path from root to data"""

    if root is None:
        return False

    path.append(root.data)

    if root.data == data:
        return True

    if ((root.left is not None and find_path(root.left, path, data) or
         root.right is not None and find_path(root.right, path, data))):
        return True

    path.pop()
    return False


def find_lca(root, node1, node2):
    """Return the lowest common ancestor of x and y"""
    path1 = []
    path2 = []

    if  not find_path(root, path1, node1) or not find_path(root, path2, node2):
        print "Error"
        return

    i = 0
    while i < len(path1) and i < len(path2) and path1[i] == path2[i]:
        i = i + 1
    return path1[i-1]


def main():
    """Runs the program"""
    root = Node("1")
    root.left = Node("2")
    root.right = Node("3")

    root.left.left = Node("4")
    root.right.right = Node("5")

    root.left.left = Node("4")
    test_path = []
    find_path(root, test_path, "4")
    assert test_path == ["1", "2", "4"]
    test_path = []
    find_path(root, test_path, "5")
    print test_path
    assert test_path == ["1", "3", "5"]
    assert find_lca(root, "2", "3") == "1"


if __name__ == "__main__":
    main()
