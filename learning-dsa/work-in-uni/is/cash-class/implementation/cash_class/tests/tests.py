import csv
import unittest
from cash_class.clean_data import (
    has_missing,
    removed_missing,
    IntervalNotFound,
    find_interval,
    AGE_INTERVALS,
    discretize_attribute
)

TEST_DATASET = "cash_class/tests/testdata/test.data"
TEST_MISSING_VALUES_DATASET = "cash_class/tests/testdata/test_missing.data"


class RemoveMissingTest(unittest.TestCase):

    def setUp(self):
        with open(TEST_MISSING_VALUES_DATASET, 'rb') as csvfile:
            reader = csv.DictReader(csvfile)
            self.instances = [row for row in reader]

    def test_has_missing_value(self):
        self.assertTrue(has_missing(self.instances[2]))

    def test_removed_missing(self):
        self.assertEqual(len(self.instances), 3)
        self.assertEqual(len(removed_missing(self.instances)), 2)


class DiscretizeDataTest(unittest.TestCase):

    def setUp(self):
        with open(TEST_MISSING_VALUES_DATASET, 'rb') as csvfile:
            reader = csv.DictReader(csvfile)
            self.instances = [row for row in reader]

    def test_find_interval(self):
        self.assertEqual(find_interval(3, [(0, 5), (5, 10), (10, 15)]),
                         (0, 5))

    def test_find_interval_outside_bounds(self):
        with self.assertRaises(IntervalNotFound):
            find_interval(100, [(0, 5), (5, 10), (10, 15)])

    def test_discretize_ages(self):
        discretize_attribute(self.instances, 'age', AGE_INTERVALS)
        self.assertIsInstance(self.instances[0]['age'], tuple)



if __name__ == '__main__':
    unittest.main()
