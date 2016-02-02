class Node:
    def __init__(self, data, previous_node=None, next_node=None, ):
        self.data = data
        self.previous_node = previous_node
        self.next_node = next_node


class DoublyLinkedList:
    def __init__(self):
        self.first = None
        self.last = None
        self.size = 0

    def add_last(self, data):
        if self.first is None:
            self.first = self.last = Node(data=data)
        else:
            new_node = Node(data, self.last, None)
            self.last.next_node = new_node
            self.last = new_node
        self.size += 1

    def add_first(self, data):
        if self.first is None:
            self.first = self.last = Node(data)
        else:
            new_node = Node(data, None, self.first)
            self.first = new_node
        self.size += 1

    def add(self, pos, data):
        if pos == 0:
            self.add_first(data)
        elif pos >= self.size:
            self.add_last(data)
        else:
            current_node = self.first
            count = 0
            while current_node is not None and count < pos - 1:
                current_node = current_node.next_node
                count += 1
            new_node = Node(data, current_node, current_node.next_node)
            current_node.next_node = new_node
        self.size += 1

    def remove_first(self):
        if self.first is None:
            raise Exception('Remove First is broken')
        else:
            self.first is not None
            self.first = self.first.next_node
            self.first.previous_node = None
        self.size -= 1

    def remove_last(self):
        if self.last is None:
            raise Exception('Remove Last is broken')
        else:
            self.last = self.last.previous_node
            self.last.next_node = None
            self.size -= 1

    def remove(pos, self):
        if pos < 0 or pos > self.size:
            raise Exception('Remove is broken')
        else:
            self.last = self.last.previous_node
            self.last.next_node = None
        self.size -= 1

    def length(self):
        count = 0
        current_node = self.first
        while current_node is not None:
            current_node = current_node.next_node
            count += 1
        return count

    def get_size(self):
        return self.size

    def show(self):
        current_node = self.first
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.next_node

    def show_reverse_order(self):
        current_node = self.last
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.previous_node


dl = DoublyLinkedList()
dl.add_first(1)
dl.add_first(2)
dl.add_first(3)
dl.add_first(4)
dl.add_first(5)
dl.add_first(6)
dl.remove_first()
dl.remove_last()
o




print(dl.get_size())
