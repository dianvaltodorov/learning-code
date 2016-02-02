class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, x):
        current_node = self.root
        previous_node = None
        while current_node is not None:
            previous_node = current_node
            if x < current_node.data:
                current_node = current_node.left
            else:
                current_node = current_node.right
        if previous_node is None:
            self.root = Node(x)
        elif x < previous_node.data:
            previous_node.left = Node(x)
        else:
            previous_node.right = Node(x)

    def print_tree_left_root_right(node):
        if node is None:
            return
        else:
            print_tree_left_root_right(node.left)
            print(node.data)
            print_tree_left_root_right(node.right)

    def print_tree_left_right_root(node):
        if node is None:
            return
        else:
            print_tree_left_right_root(node.left)
            print_tree_left_right_root(node.right)
            print(node.data)

    def print_tree_root_left_right(node):
        if node is None:
            return
        else:
            print(node.data)
            print_tree_root_left_right(node.left)
            print_tree_root_left_right(node.right)

    def get_minimum(self):
        current_node = self.root
        previous_node = None
        while current_node is not None:
            previous_node = current_node
            current_node = current_node.left
        if previous_node is None:
            print("tree empty")
        else:
            return previous_node.data

    def get_maximum(self):
        current_node = self.root
        previous_node = None
        while current_node is not None:
            previous_node = current_node
            current_node = current_node.right
        if previous_node is None:
            print("tree empty")
        else:
            return previous_node.data

    def search(self, x):
        current_node = self.root
        while current_node is not None and x != current_node.data:
            if x < current_node.data:
                current_node = current_node.left
            else:
                current_node = current_node.right
        if current_node is None:
            print "Element not found"
        else:
            return x

bt = BinarySearchTree()
bt.insert(3)
bt.insert(5)
bt.insert(2)
bt.insert(9)
print(bt.search(3))
bt.print_tree()
print(bt.get_minimum())
print(bt.get_maximum())
bt.insert(3)
bt.insert(
    jj
