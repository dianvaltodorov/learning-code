from cash_class.clean_data import clean
import csv

from cash_class.naive_bayes_classifier import NaiveBayesClassifier


DATASET = "data/train.data"
TEST_DATASET = "data/test.data"


def parse_instances(path):
    with open(path, 'rb') as csvfile:
        reader = csv.DictReader(csvfile)
        instances = [row for row in reader]
    return instances


if __name__ == "__main__":
    raw_instances = parse_instances(DATASET)
    raw_test = parse_instances(TEST_DATASET)
    tests = clean(raw_test)
    instances = clean(raw_instances)
    nbc = NaiveBayesClassifier(instances)
    hits = 0
    miss = 0
    for t in tests:
        if nbc.predict(t) == t['income']:
            hits += 1
    print float(hits) / len(tests)
