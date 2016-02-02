def digitize(n):
    res = []
    while (n > 0):
        res.append(n % 10)
        n = n / 10
    return res


print digitize(348)


def digitize1(n):
    return map(int, str(n)[::-1])


def digitize2(n):
    return [int(x) for x in str(n)[::-1]]
