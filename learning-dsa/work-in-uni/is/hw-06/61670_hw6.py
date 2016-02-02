import csv
import math
from sklearn.model_selection import train_test_split
import heapq
import operator

entries = []
with open('testdata/iris.data') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for row in reader:
        entries.append([
            float(row[0]),
            float(row[1]),
            float(row[2]),
            float(row[3]),
            row[4]
        ])
train, test = train_test_split(entries, test_size=0.13)


def predict(neighbors):
    class_votes = {}
    for n in neighbors:
        response = n[-1]
        if response in class_votes:
            class_votes[response] += 1
        else:
            class_votes[response] = 1
    votes = sorted(class_votes.iteritems(), key=operator.itemgetter(1), reverse=True)
    return votes[0][0]


def euclidean_distance(x, y, length):
    distance = 0
    for i in xrange(length):
        distance += (x[i] - y[i]) ** 2
    return math.sqrt(distance)


def get_neighbors(p, train_data, k):
    distances = []
    for t in train_data:
        dist = euclidean_distance(p, t, len(t) - 1)
        heapq.heappush(distances, (dist, t))
    return [heapq.heappop(distances)[1] for i in xrange(k)]


k = input()
hit = 0
miss = 0

for p in test:
    neighbors = get_neighbors(p, train, k)
    prediction = predict(neighbors)
    print "Prediction: {}, Real: {}".format(prediction, p[-1])
    if prediction == p[-1]:
        hit += 1
    else:
        miss += 1

print str(float(hit) / len(test) * 100.0) + "%"
