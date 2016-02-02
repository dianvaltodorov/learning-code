from math import hypot


class Vector(object):

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return 'Vector(x = {}, y = {})'.format(self.x, self.y)

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, scalar):
        return Vector(self.x * scalar,  self.y * scalar)

    def __rmul__(self, scalar):
        return Vector(self.x * scalar,  self.y * scalar)


v1 = Vector(1, 3)
v2 = Vector(4, 5)
v3 = Vector(9, 2)
v4 = v1 * 2
v5 = 3 * v1
v6 = v1 + v2
# v7 = v1 * v2  # unsupported
print(v1)
print(v2)
print(v3)
print(v4)
print(v5)
print(v6)
# print(v7)
