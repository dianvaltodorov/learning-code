def pattern(n):
    res = '1\n'
    for i in range(1, n):
        res = res + '1' + i * '*' + str(i + 1) + '\n'
    return res[-1]

