import random


def nqueens(n):
    solved_board = solve(list(range(n)))
    show(solved_board)


def initial_state(n):
    conflicts = [0] * n
    for i in xrange(n):
        random.choice(i for i in xrange(i) if conflicts[i] == min(conflicts))


def show(board):
    n = len(board)
    for i in range(n):
        row = ['-'] * n
        for col in range(n):
            if board[col] == i:
                row[col] = '*'
        print(''.join(row))


Ефективност на евристична функция. 
0 в целевото състояние

Оптимален, Пълен

консистента

Бест фърст сърч

Пълнота оптималност и памет

def solve(board,  max_steps=100000):
    n = len(board)
    for k in xrange(max_steps):
        # find all the conflicts for the current configuration
        conflicts = find_all_conflicts(board)
        if sum(conflicts) == 0:  # Checked every queen and found no conflicts
            return board
        # TODO: 
        # randomly choose a queen with max conflicts
        col = random.choice([i for i in xrange(n) if conflicts[i] == max(conflicts)])
       
        # try putting the queen on each possible row
        x_conflicts = [threats(board, col, row) for row in range(n)]
        board[col] = random.choice([i for i in xrange(n) if x_conflicts[i] == min(x_conflicts)])
    print "Exceeded max_steps"


def threats(board, col, row):
    """
    Returns the number of queens that conflict with (row,col), not
    counting the queen in column col.
    """
    total = 0
    for i in xrange(len(board)):
        # we can not have two queens on the same column
        if i == col:
            continue

        # have a threat on the same row
        if board[i] == row:
            total += 1
        # a little like manhathan distance
        if abs(i - col) == abs(board[i] - row):
            total += 1
    return total


def find_all_conflicts(board):
    n = len(board)
    return [threats(board, col, board[col]) for col in range(n)]

n = input()
nqueens(n)

# each is threated by all the other on the diagonals
assert find_all_conflicts(range(8)) == [7, 7, 7, 7, 7, 7, 7, 7]
assert threats(range(8), 2, 4) == 2  # one diagonal and on the same row
assert threats(range(8), 2, 5) == 1  # one on the same row
