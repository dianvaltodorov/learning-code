class Node:

    def __init__(self, data, next=None):
        self.next = next
        self.data = data


def nth_from_reverse(head, n):
    p1 = head
    p2 = head
    for i in range(n):
        if p1 is None:
            return

        i += 1
        p1 = p1.next

    while p2.next:
        p1 = p1.next
        p2 = p2.next

    return p1.data

