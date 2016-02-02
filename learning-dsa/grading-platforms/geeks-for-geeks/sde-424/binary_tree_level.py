class Node:
    def __init__(self, data: int, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def find_level(root, target, level):
    if not root:
        return 0

    if target == root.data:
        return level

    down_level = find_level(root.left, target, level + 1)
    if down_level != 0:
        return down_level
    else:
        return find_level(root.right, target, level + 1)


def solve():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(18)
    root.left.left = Node(5)
    root.left.right = Node(7)
    root.right.left = Node(100)
    print(find_level(root, 100, 1))
    print(find_level(root, 2, 1))
    print(find_level(root, 1, 1))

solve()