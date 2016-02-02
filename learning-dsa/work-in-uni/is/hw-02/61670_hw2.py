from heapq import heappush, heappop

width = input()
start = input()

width = 3
FINAL_STATE = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
# [[1, 2, 3], [4, 5, 6], [7, 0, 8]]
# [[1, 2, 3], [4, 5, 6], [0, 7, 8]]
# [[2, 3, 0], [1, 6, 8], [7, 5, 4]]

# [[6, 5, 3], [2, 4, 8], [7, 0, 1]]
# [[2, 3, 6], [1, 5, 8], [4, 7, 0]]

def is_solved(state):
    return state == FINAL_STATE


def heur(board):
    """Calculates manhathan_distance"""
    man_dist = 0
    for i in range(width):
        for j in range(width):
            if board[i][j] == 0:
                continue
            final_row = (board[i][j] - 1) / width
            final_column = (board[i][j] - 1) % width
            dist = abs(final_row - i) + abs(final_column - j)
            man_dist = man_dist + dist
    return man_dist


def empty(board):
    for idx, row in enumerate(board):
        if 0 in row:
            column = row.index(0)
            return idx, column
    return Exception("Empty not found")


def legal_moves(board):
    row, col = empty(board)
    legal_moves = []

    if row > 0:
        legal_moves.append((row - 1, col, 'down'))
    if col > 0:
        legal_moves.append((row, col - 1, 'right'))
    if row < width - 1:
        legal_moves.append((row + 1, col, 'up'))
    if col < width - 1:
        legal_moves.append((row, col + 1, 'left'))

    return legal_moves


def clone(board):
    return [row[:] for row in board]


def neighbours(board):
    neighbours = []
    row, col = empty(board)
    for i, j, move in legal_moves(board):
        new_state = clone(board)
        new_state[i][j], new_state[row][col] = new_state[row][col], new_state[i][j]
        neighbours.append((new_state, move))
    return neighbours


def construct_path(came_from, current_state):
        total_path = []
        current = str(current_state)
        while current in came_from:
            current, move = came_from[str(current)]
            total_path.append(move)
        return total_path


def solve(start_state, width):
    g_score = {str(start_state): 0}
    f_score = []
    heappush(f_score, (heur(start_state) + g_score[str(start_state)], start_state))

    came_from = dict()

    while f_score:
        _, current = heappop(f_score)

        if is_solved(current):
            return construct_path(came_from, current)

        for n, move in neighbours(current):
            new_g_score = g_score[str(current)] + 1

            if str(n) not in g_score or new_g_score < g_score[str(n)]:
                g_score[str(n)] = new_g_score
                new_f_score = new_g_score + heur(n)
                heappush(f_score, (new_f_score, n))
                came_from[str(n)] = str(current), move

sol = solve(start, width)
for s in sol:
    print s
print len(sol)