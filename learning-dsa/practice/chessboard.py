import itertools

board1 = [
    "ab",
    "ba"
]
out1 = 0

board2 = [
    "ababa",
    "bacab",
    "ababd",
    "babab",
    "ababa",
]
out2 = 2

board3 = [
    "abc",
    "def",
    "ghi"
]
out3 = 7

board4 = [
    "yyxyxy",
    "yxyxyx",
    "xyxyxy",
    "yxyxyx",
    "xyxyxy",
    "yxyxyx",
]
out4 = 1


def convert_board(board):
    return [list(row) for row in board]


def get_alphabet(board):
    res = []
    for row in board:
        res = res + row
    return set(res)


def get_pairs(alphabet):
    if len(alphabet) == 1:
        return [(alphabet[0], -1)]
    return list(itertools.combinations(alphabet, 2))


def gen_board(pair, size):
    res = []
    for i in xrange(size):
        row = []
        if i % 2 == 0:
            for j in xrange(size):
                if j % 2 == 0:
                    row.append(pair[0])
                else:
                    row.append(pair[1])
        else:
            for j in xrange(size):
                if j % 2 == 0:
                    row.append(pair[1])
                else:
                    row.append(pair[0])
        res.append(row)
    return res


def delta(board, target):
    res = 0
    for i, row in enumerate(board):
        for j, c in enumerate(row):
            if c != target[i][j]:
                res += 1
    return res


def solve(input):
    min_repl = 16 ** 2
    board = convert_board(input)
    alphabet = get_alphabet(board)
    pairs = get_pairs(alphabet)
    for p in pairs:
        target1 = gen_board(p, len(input))
        d1 = delta(board, target1)
        if d1 < min_repl:
            min_repl = d1

        target2 = gen_board((p[1], p[0]), len(input))
        d2 = delta(board, target2)
        if d2 < min_repl:
            min_repl = d2
    return min_repl


assert solve(board1) == out1
assert solve(board2) == out2
assert solve(board3) == out3
assert solve(board4) == out4
