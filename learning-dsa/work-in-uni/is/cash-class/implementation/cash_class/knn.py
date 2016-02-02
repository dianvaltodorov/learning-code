import math
import heapq
import operator

CONT_ATTRIBUTES = ['capital-gain', 'capital-loss',
                   'hours-per-week', 'fnlwgt', 'age']

K = 6


class KNeighborsClassifier(object):

    def __init__(self, instances):
        self.instances = instances

    def euclidean_distance(self, x, y):
        distance = 0
        for attr in CONT_ATTRIBUTES:
            distance += (int(x[attr]) - int(y[attr])) ** 2
        return math.sqrt(distance)

    def get_neighbours(self, inst, k):
        distances = []
        for t in self.instances:
            dist = self.euclidean_distance(inst, t)
            heapq.heappush(distances, (dist, t))
        return [heapq.heappop(distances)[1] for i in xrange(k)]

    def predict(self, inst):
        neighbours = self.get_neighbours(inst, K)
        votes = {'>50K': 0, '<=50K': 0}
        for n in neighbours:
            votes[n['income']] += 1
        return max(votes, key=operator.itemgetter(1))
