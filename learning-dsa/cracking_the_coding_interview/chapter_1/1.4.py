from collections import defaultdict

NO_OF_CHARS = 256


def sorted_soluion(x, y):
    return x.sorted() == y.sorted()


def dict_solution(x, y):
    xmap = defaultdict(int)
    for c in x:
        xmap[c] += 1

    ymap = defaultdict(int)
    for x in y:
        ymap[c] += 1

    return ymap.keys() == xmap.keys() and ymap.values() == xmap.values()


def list_solution(x, y):
    if x.length != y.length:
        return False

    xlist = [0] * NO_OF_CHARS
    ylist = [0] * NO_OF_CHARS

    length = x.length
    for i in range(length):
        xlist[x[i]] += 1
        ylist[y[i]] += 1

    for i in range(NO_OF_CHARS):
        if xlist[i] != ylist[i]:
            return False

    return True
