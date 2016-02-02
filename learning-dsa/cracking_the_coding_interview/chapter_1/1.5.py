def solve(x, y):
    if len(x) != len(y):
        return False

    y = y + y
    return y in x


