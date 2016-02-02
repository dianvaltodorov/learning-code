import csv


def parse_instances(path):
    with open(path, 'rb') as csvfile:
        reader = csv.DictReader(csvfile)
        instances = [row for row in reader]
    return instances

def split_test_into_train_and_test():
    pass