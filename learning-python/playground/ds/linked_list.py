class Node:
    def __init__(self, data, next_node):
        self.data = data
        self.next_node = next_node


class LinkedList:
    def __init__(self, first=None, last=None):
        self.first = first
        self.last = last

    def append(self, data):
        new_node = Node(data, None)
        if self.first is None:
            self.first = new_node
            self.last = new_node
        else:
            self.last.next_node = new_node
            self.last = self.last.next_node

    def insert(self, pos, data):
        if self.first is None:
            new_node = Node(data, None)
            self.first = new_node
            self.last = new_node
        elif pos == 0:
            new_node = Node(data, self.first)
            self.first = new_node
        else:
            current_node = self.first
            counter = 0
            while current_node is not None and counter < pos - 1:
                counter += 1
                current_node = current_node.next_node
            current_node.next_node = Node(data, current_node.next_node)

    def remove(self, n):
        if self.first is None:
            print("Linked List is empty")
        elif n == 0:
            self.first = Node(data, self.first)
            self.first = new_node
        else:
            current_node = self.first
            counter = 0
            while current_node is not None and counter < n - 1:
                current_node = current_node.next_node
                counter += 1
            if counter == n - 1:
                current_node.next_node = Node(data, current_node.next_node)
            else:
                print "Array Out Of Bounds"

    def length(self):
        size = 0
        current_node = self.first
        while current_node is not None:
            current_node = current_node.next_node
            size += 1
            return size

    def show(self):
        current_node = self.first
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.next_node

    def get(self, pos):
        count = 0
        current_node = self.first
        while current_node is not None and count < pos:
            current_node = current_node.next_node
            count += 1
        if current_node is not None:
            return current_node.data
        else:
            print("array out of Bounds")

x = list()
l = LinkedList()
l.append(1)
l.append(2)
l.insert(2, 3)
l.insert(3, 8)
l.insert(4, 4)
l.insert(5, 9)
l.insert(0, 19)
l.insert(0, 21)
l.insert(0, 42)
l.insert(0, 1999)
l.show()
print("")
print(l.get(3))

print(l.length())
