"""Implementation of the classical dijkstra algorithm"""

import sys
from heapq import *


class Graph(object):
    """A data structure representing a weighted graph"""

    def __init__(self):
        self.vertices = {}

    def add_edge(self, u, v, len):
        """add a new edge"""
        self.vertices[u] = v, len
        self.vertices[v] = u, len

    def shortest_paths(self, start):
        distances = {}
        visited = {}
        nodes = []


        for vertex in self.vertices:
            if vertex == start:
                distances[vertex] = 0
                heappush(nodes, [0, vertex])
            else:
                distances[vertex] = sys.maxsize
                heappush(nodes, [0, vertex])

        while nodes:
            smallest = heappop(nodes)

            if distances[smallest] == sys.maxsize:
                break
            
            for neigh in self.vertices[smallest]:
                alt = distances[smallest] + self.vertices[smallest][neigh]

                if alt