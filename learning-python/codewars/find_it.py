import operator


def find_it(seq):
    items = set(seq)
    occurences = {x: seq.count(x) for x in items}
    for key, value in occurences.iteritems():
        if value % 2 == 0:
            return key

print find_it([1, 2, 2, 3, 1, 12, 3, 34, 5, 53, 2, 2, 2, 3, 4, 4, 2, 1, 2, 3])


def find_it1(seq):
    for i in seq:
        if seq.count(i) % 2 != 0:
            return i


def find_it(xs):
    return reduce(operator.xor, xs)
