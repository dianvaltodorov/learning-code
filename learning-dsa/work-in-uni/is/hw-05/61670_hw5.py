import random


class TicTacToe(object):
    winning_combos = (
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6])

    def __init__(self, boxes=[]):
        if len(boxes) == 0:
            self.boxes = [None for i in range(9)]
        else:
            self.boxes = boxes

    def print_board(self):
        for element in [self.boxes[i:i + 3] for i in range(0, len(self.boxes), 3)]:
            print element

    def possible_moves(self):
        return [k for k, v in enumerate(self.boxes) if v is None]

    def make_move(self, position, player):
        self.boxes[position] = player

    def game_over(self):
        if None not in [v for v in self.boxes]:
            return True
        if self.winner() is not None:
            return True
        return False

    def winner(self):
        for player in ('X', 'O'):
            positions = self.get_squares_for_player(player)
            for combo in self.winning_combos:
                win = True
                for pos in combo:
                    if pos not in positions:
                        win = False
                if win:
                    return player
        return None

    def get_squares_for_player(self, player):
        return [k for k, v in enumerate(self.boxes) if v == player]

    def max_wins(self):
        return self.winner() == 'X'

    def min_wins(self):
        return self.winner() == 'O'

    def draw(self):
        return self.game_over() is True and self.winner() is None

    def alpha_beta(self, node, player, alpha, beta):
        if node.game_over():
            if node.max_wins():
                return -1
            elif node.draw():
                return 0
            elif node.min_wins():
                return 1
        for move in node.possible_moves():
            node.make_move(move, player)
            score = self.alpha_beta(node, enemy(player), alpha, beta)
            node.make_move(move, None)
            if player == 'O': # min
                if score > alpha:
                    alpha = score
                if alpha >= beta:
                    return beta
            else: # max
                if score < beta:
                    beta = score
                if beta <= alpha:
                    return alpha
        if player == 'O':
            return alpha
        else:
            return beta


def computer_input(board, player):
    a = -2
    choices = []
    for move in board.possible_moves():
        board.make_move(move, player)
        score = board.alpha_beta(board, enemy(player), -2, 2)
        board.make_move(move, None)
        if score > a:
            a = score
            choices = [move]
        elif score == a:
            choices.append(move)

    return random.choice(choices)


def enemy(player):
    if player == 'X':
        return 'O'
    return 'X'


if __name__ == "__main__":
    board = TicTacToe()
    board.print_board()

    while not board.game_over():
        # Human input
        player = 'X'
        player_move = int(raw_input("Next Move: ")) - 1
        if not player_move in board.possible_moves():
            print "Box taken"
            continue
        board.make_move(player_move, player)
        board.print_board()

        if board.game_over():
            break

        # computer move
        player = enemy(player)
        computer_move = computer_input(board, player)
        board.make_move(computer_move, player)
        board.print_board()
    print "winner is", board.winner()
