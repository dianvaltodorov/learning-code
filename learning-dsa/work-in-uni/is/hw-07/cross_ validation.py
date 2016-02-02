import csv

from classifier import BayesClassifier
import random
import itertools

with open('vote.data') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    politicians = [p for p in reader]

random.shuffle(politicians)
k = 10
chunk = len(politicians) / k
buckets = zip(*[iter(politicians)]*chunk)

res = 0.0
for idx, b in enumerate(buckets):
    train = buckets[:idx] + buckets[idx+1:]
    test = buckets[idx]
    classifier = BayesClassifier(list(itertools.chain.from_iterable(train)))
    hit = 0
    miss = 0
    for t in test:
        if classifier.classify(t) == t[-1]:
            hit = hit + 1
        else:
            miss = miss + 1
    success_rate = float(hit) / (hit + miss)
    res = res + success_rate


print res / k
