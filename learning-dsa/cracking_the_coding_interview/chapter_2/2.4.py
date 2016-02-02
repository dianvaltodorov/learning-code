class Node:

    def __init__(self, data, next=None):
        self.next = next
        self.data = data


n1 = Node(3)
n1.next = Node(1)
n1.next.next = Node(5)

n2 = Node(5)
n2.next = Node(9)
n2.next.next = Node(2)


def calculate_sum(n1, n2):
    sentinel = Node(0)
    head = sentinel
    carry = 0
    while n1 and n2:
        val = n1.data + n2.data + carry
        carry = val // 10
        node = Node(val % 10)
        head.next = node
        head = head.next
        n1 = n1.next
        n2 = n2.next

    return sentinel.next


n = calculate_sum(n1, n2)
print(10)
