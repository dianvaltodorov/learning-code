from enum import Enum


class Difficulty(Enum):
    EASY = 0
    MEDIUM = 1
    HARD = 2


class Cell:

    def __init__(self, opened=False, has_mine=False, neighbour_mines=0):
        self.is_mine = has_mine
        self.neighbour_mines = neighbour_mines
        self.opened = opened


class GameOverException(Exception):
    pass


class Board:

    def __init__(self, w: int, h: int, mines_count: int):
        self.w = w
        self.h = h
        if w * h > mines_count:
            raise Exception("Mines more than board size")

        self.mines_count = mines_count
        self.mine_locations = []
        self.cells = [[Cell() for j in range(w)] for i in range(h)]

    def start_game(self, x: int, y:int):
        self._set_all_mines(x, y)
        self._put_neighbour_indicators()
        self.open(x, y)

    def _set_all_mines(self, x, y):
        self.mine_locations = self._get_mine_location(x, y)
        for ml in self.mine_locations:
            i, j = ml
            self.cells[i][j].is_mine = True

    def _put_neighbour_indicators(self):
        for i in range(self.h):
            for j in range(self.w):
                self.cells[i][j].neighbour_mines = self._get_neighbouring_mines_count(i, j)

    def _get_neighbouring_mines_count(self, x, y):
        return self.cells[x][y + 1].is_mine + self.cells[x][y - 1].is_mine \
               + self.cells[x + 1][y].is_mine + self.cells[x - 1][y].is_mine \
               + self.cells[x - 1][y - 1].is_mine + self.cells[x - 1][y + 1].is_mine \
               + self.cells[x + 1][y + 1].is_mine + self.cells[x + 1][y - 1].is_mine

    def _get_mine_locations(self, excluded_x, excluded_y):
        return []

    def open(self, x, y):
        if self.cells[x][y].is_mine:
            raise GameOverException

        queue = [(x, y)]
        while queue:
            i, j = queue.pop()
            neighbours = self._get_neighbours(i, j)
            for n in neighbours:
                ii, jj = n
                self.cell[ii][jj].is_opened = True

                if self.cells[ii][jj].neighbour_mines == 0:
                    queue.append((ii, jj))

                if self.cells[ii][jj].neighbour_mines > 0:
                    queue.append((ii, jj))

    def _get_neighbours(self, i, j):
        return [(i + 1, j), (j + 1)]


class Game:

    def __init__(self):
        self.board = Board()
        self.timer = Timer()


b = Board()
