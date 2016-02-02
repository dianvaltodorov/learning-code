from fabric.api import local

from cash_class.plot import save_all_hists, plot_hist
from cash_class.parse import parse_instances
from cash_class.clean_data import clean_for_bayes, clean_for_knn

from cash_class.naive_bayes_classifier import NaiveBayesClassifier
from cash_class.knn import KNeighborsClassifier
from cash_class.validation import validation

DATASET = 'data/income-train.data'
TEST_DATASET = 'data/income-test.data'
VALIDATE_DATASET = 'data/income-validate.data'


def test():
    local("python -m unittest discover")


def save_hists():
    instances = parse_instances(DATASET)
    save_all_hists(instances)


def plot_attr_hist(attr):
    instances = parse_instances(DATASET)
    plot_hist(instances, attr)


def bayes():
    raw_instances = parse_instances(DATASET)
    instances = clean_for_bayes(raw_instances)

    raw_tests_instances = parse_instances(TEST_DATASET)
    tests = clean_for_bayes(raw_tests_instances)

    raw_validation_instances = parse_instances(VALIDATE_DATASET)
    val_insts = clean_for_bayes(raw_validation_instances)

    print validation(instances, val_insts, NaiveBayesClassifier)
    print validation(instances, tests, NaiveBayesClassifier)


def knn():
    raw_instances = parse_instances(DATASET)
    instances = clean_for_knn(raw_instances)

    raw_tests_instances = parse_instances(TEST_DATASET)
    tests = clean_for_knn(raw_tests_instances)

    raw_validation_instances = parse_instances(VALIDATE_DATASET)
    val_insts = clean_for_knn(raw_validation_instances)

    print validation(instances, val_insts, KNeighborsClassifier)
    print validation(instances, tests, KNeighborsClassifier)


def decision_tree():
    pass
