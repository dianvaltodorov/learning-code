# Program to print BFS traversal from a given source
# vertex. BFS(int s) traverses vertices reachable
# from s.
from collections import defaultdict
 
class Graph:
 
    def __init__(self):
        self.graph = defaultdict(list)
 
    def add_edge(self,u,v):
        self.graph[u].append(v)
 
    def bfs(self, s):
        visited = [False] * (len(self.graph))
        queue = []
        queue.append(s)
        visited[s] = True
 
        while queue:
 
            s = queue.pop(0)
            print s,
 
            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
    
    def dfs(self, s):
        self.visited = [False] * (len(self.graph))
        queue = []
        queue.append(s)
        self.visited[s] = True
        self._dfs_helper(s)

    def _dfs_helper(self, s):
        print s,
        self.visited[s] = True
        for u in self.graph[s]:
            if not self.visited[u]:
                self._dfs_helper(u)

# Driver code
# Create a graph given in the above diagram
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)
 
print "Following is Breadth First Traversal (starting from vertex 2)"
g.bfs(2)
g.dfs(2)
 