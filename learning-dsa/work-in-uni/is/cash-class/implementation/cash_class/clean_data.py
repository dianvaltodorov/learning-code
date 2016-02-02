"""Clean data utilities"""
MIN_AGE = 15
MAX_AGE = 100
AGE_STEP = 5
AGE_INTERVALS = [(i, i + AGE_STEP)for i in xrange(MIN_AGE, MAX_AGE, AGE_STEP)]


MIN_GAIN = 0
MAX_GAIN = 100000
GAIN_STEP = 300
GAIN_INTERVALS = [(i, i + GAIN_STEP)
                  for i in xrange(MIN_GAIN, MAX_GAIN, GAIN_STEP)]

MIN_LOSS = 0
MAX_LOSS = 10000
LOSS_STEP = 200
LOSS_INTERVALS = [(i, i + LOSS_STEP)
                  for i in xrange(MIN_LOSS, MAX_LOSS, LOSS_STEP)]

MIN_HOURS = 0
MAX_HOURS = 102
HOURS_STEP = 3
HOURS_INTERVALS = [(i, i + HOURS_STEP)
                   for i in xrange(MIN_HOURS, MAX_HOURS, HOURS_STEP)]

MIN_FNLWGT = 0
MAX_FNLWGT = 800000
FNLWGT_STEP = 50000
FNLWGT_INTERVALS = [(i, i + FNLWGT_STEP)
                    for i in xrange(MIN_FNLWGT, MAX_FNLWGT, FNLWGT_STEP)]


class IntervalNotFound(Exception):
    """Raisesd when value not found in any of the provided intervals"""
    pass


def find_interval(value, intervals):
    for interval in intervals:
        if value >= interval[0] and value < interval[1]:
            return interval
    raise IntervalNotFound('value {} not in {}'.format(value, intervals))


def discretise_attribute(instances, attribute, intervals):
    def helper(instance):
        interval = find_interval(int(instance[attribute]), intervals)
        instance[attribute] = interval
        return instance
    return [helper(inst) for inst in instances]


def discretize_all(instances):
    ds = discretise_attribute(instances, 'age', AGE_INTERVALS)
    ds = discretise_attribute(ds, 'capital-gain', GAIN_INTERVALS)
    ds = discretise_attribute(ds, 'capital-loss', LOSS_INTERVALS)
    ds = discretise_attribute(ds, 'hours-per-week', HOURS_INTERVALS)
    ds = discretise_attribute(ds, 'fnlwgt', FNLWGT_INTERVALS)
    return ds


def trim_outliers(instances, attr, interv):
    return [inst for inst in instances
            if interv[0] <= int(inst[attr]) and int(inst[attr]) < interv[1]]


def trim_outliers_for_all(instances):
    trimmed = trim_outliers(instances, 'age', (MIN_AGE, MAX_AGE))
    trimmed = trim_outliers(trimmed, 'capital-gain', (MIN_GAIN, MAX_GAIN))
    trimmed = trim_outliers(trimmed, 'capital-loss', (MIN_LOSS, MAX_LOSS))
    trimmed = trim_outliers(trimmed, 'hours-per-week', (MIN_HOURS, MAX_HOURS))
    trimmed = trim_outliers(trimmed, 'fnlwgt', (MIN_FNLWGT, MAX_FNLWGT))
    return trimmed


def has_missing(instance):
    return len([v for v in instance.values() if v == '?']) > 0


def removed_missing(instances):
    return [instance for instance in instances
            if not has_missing(instance)]


def clean_for_bayes(instances):
    no_missing = removed_missing(instances)
    trimmed = trim_outliers_for_all(no_missing)
    discretized = discretize_all(trimmed)
    return discretized


def clean_for_knn(instances):
    no_missing = removed_missing(instances)
    return no_missing
