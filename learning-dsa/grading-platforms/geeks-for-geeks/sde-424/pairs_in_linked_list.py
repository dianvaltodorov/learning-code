class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


def solution_one(x: Node, target: int):
    temp1 = x
    count = 0
    while temp1 and temp1.next:
        print(temp1.data)
        temp2 = temp1.next
        while temp2:
            if temp1.data + temp2.data == target:
                count += 1
            print("   ", temp2.data)
            temp2 = temp2.next
        temp1 = temp1.next
    return count


def solution_two(x: Node, target: int):
    temp = x
    count = 0
    occurrences = set()
    while temp:
        occurrences.add(temp.data)
        temp = temp.next
    print(occurrences)
    count = 0
    temp = x
    while temp:
        print(temp.data, target - temp.data)
        if target - temp.data in occurrences:
            count += 1
        temp = temp.next
    return count


def solution_three(x: Node, target: int):
    temp = x
    res = 0
    counts = {}
    while temp:
        counts[temp.data] = counts.get(temp.data, 0) + 1
        temp = temp.next
    print(counts)
    return res


def solve():
    x = Node(0)
    x.next = Node(2)
    x.next.next = Node(5)
    x.next.next.next = Node(7)
    x.next.next.next.next = Node(4)
    x.next.next.next.next.next = Node(6)
    x.next.next.next.next.next.next = Node(10)
    x.next.next.next.next.next.next.next = Node(20)
    x.next.next.next.next.next.next.next.next = Node(-10)
    x.next.next.next.next.next.next.next.next.next = Node(2)
    x.next.next.next.next.next.next.next.next.next.next = Node(7)
    x.next.next.next.next.next.next.next.next.next.next.next = Node(6)
    x.next.next.next.next.next.next.next.next.next.next.next.next = Node(6)
    # print(solution_one(x, 10))
    print(solution_three(x, 10))


solve()
