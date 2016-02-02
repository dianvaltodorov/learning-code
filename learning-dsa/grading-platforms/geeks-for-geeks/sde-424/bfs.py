from collections import deque, defaultdict

g = defaultdict(list)

g['A'] = ['B', 'C']
g['B'] = ['H', 'F', 'D']
g['C'] = ['E', 'G']
g['E'] = ['Z']


def bfs(graph, start):
    used = [False] * len(graph)

    q1 = deque()
    q2 = deque()
    q1.append(start)

    used = defaultdict(lambda: False)
    while q1 or q2:
        while q1:
            current = q1.popleft()
            print(current, end=" ")
            for neigh in graph[current]:
                if not used[neigh]:
                    q2.append(neigh)
                    used[neigh] = True
        print()
        while q2:
            current = q2.popleft()
            print(current, end=" ")
            for neigh in graph[current]:
                if not used[neigh]:
                    q1.append(neigh)
                    used[neigh] = True
        print()


bfs(g, 'A')
