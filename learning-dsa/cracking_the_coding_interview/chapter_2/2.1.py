class Node:

    def __init__(self, data, next=None):
        self.next = next
        self.data = data


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, x):
        if self.head is None:
            self.head = Node(x)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(x)


def remove_duplicates(linked_list):
    current = linked_list.head
    sset = set()
    sset.add(current.data)

    while current.next:
        current.data
        current = current.next

