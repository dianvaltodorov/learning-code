import random
import itertools


def validation(instances, test_instances, classifier):
    c = classifier(instances)
    hits = 0
    for t in test_instances:
        x = c.predict(t)
        if x == t['income']:
            hits += 1
    return float(hits) / len(test_instances)


# def cross_validation(instances, k, classifier):
#     random.shuffle(instances)
#     k = 10
#     chunk = len(instances) / k
#     buckets = zip(*[iter(instances)]*chunk)

#     import ipdb; ipdb.set_trace()
#     c = classifier(instances)

#     res = 0.0
#     for idx, b in enumerate(buckets):
#         train = buckets[:idx] + buckets[idx+1:]
#         test = buckets[idx]
#         classifier = BayesClassifier(list(itertools.chain.from_iterable(train)))
#         hit = 0
#         miss = 0
#         for t in test:
#             if classifier.predict(t) == t['income']:
#                 hit = hit + 1
#             else:
#                 miss = miss + 1
#         success_rate = float(hit) / len(test)
#         res = res + success_rate
#     return res / k
