from collections import defaultdict


class Workbook:

    def __init__(self, name):
        self.sheets = {}  # {sheet_id: Sheet)

    def new_sheet(self, name):
        sheet = Spreadsheet(name)
        self.sheets[name] = sheet

    def remove_sheet(self, name):
        del self.sheets[name]

    def get_sheet(self, name):
        return self.sheets[name]


class Cell:

    def __init__(self, value=None, formula=None):
        self.formula = formula
        self.value = value

    @property
    def value(self):



class Spreadsheet:

    def __init__(self, name):
        self.name = name
        self.matrix = defaultdict(lambda: defaultdict(Cell))

    def set(self, row, col, value):
        self.matrix[row][col] = value

    def get(self, row, col):
        return self.matrix[row][col]

    def refresh(self):
        for i in self.matrix:
            for j in self.matrix[i]:
                eval(self.matrix.get(i, j))

    def print(self):
        for i in self.matrix:
            for j in self.matrix[i]:
                (self.matrix.get(i, j), "")
            print()


if __name__ == '__main__':
    wb = Workbook("wb1")
    wb.new_sheet("sh1")
    sheet = wb.get_sheet("sh1")
    sheet.set(1, 1, 10)
    sheet.set(1, 1, 10)
    sheet.set(1, 1, 10)
    sheet.set(1, 1, 10)
    sheet.print()
