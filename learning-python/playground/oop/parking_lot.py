global


class Vehicle:
    def __init__(self, plate, make, year, owner):
        self._plate = plate
        self._make = make
        self._year = year
        self._owner = owner


class Customer:
    def __init__(self, name, phone, mail):
        self._name = name
        self._phone = phone
        self._mail = mail


class Space:
    def __init__(self):
        self.vehicle = None
        self.in_time = 0

    def take(self, vehicle, in_time):
        self.vehicle = vehicle
        self.in_time = in_time

    def free(self):
        self.vehicle = None
        self.in_time = 0

    def is_free(self):
        return self.vehicle is None


class ParkinLot:
    def __init__(self, width=0, height=0):
        self.width = width
        self.height = height
        self.available_spaces = width * height
        self.spaces = [[Space() for j in range(width)] for i in range(height)]

    def is_parking_space_free(self, x, y):
        return self.spaces[x][y].is_free()

    def get_free_parking_space(self):
        for i, row in enumerate(self.spaces):
            for j, sp in enumerate(row):
                if spaces[i][j].is_free():
                    return i, j

    def is_capacity_reached(self):
        return self.available_spaces == 0

    def park_vehicle(self, vehicle):
        if self.is_capacity_reached():
            print("Cannot park car")
        else:
            i, j = self.get_free_parking_space()
            self.space[i][j].take(vehicle)

    def free_space(self, x, y):
        self.space[x][y].free()



pl = ParkinLot(3, 9)

dian = Customer("Dian", "0888129834", "dian@example")
bob = Customer("Bob", "0888123434", "bob@example")
joe = Customer("Joe", "0888121234", "joe@example")

opel = Vehicle("1234", "Opel", 1994, dian)
bmw = Vehicle("7832", "BMW", 1994, dian)
mustang = Vehicle("1247", "Mustang", 1994, dian)
aston = Vehicle("0842", "Aston", 1994, dian)

i, j
