import abc
from abc import ABCMeta
from enum import Enum


class VehicleSize(Enum):
    MOTORCYCLE = 0
    COMPACT = 1
    LARGE = 2


class Vehicle(metaclass=ABCMeta):

    def __init__(self, vehicle_size, license_plate, spot_size):
        self.vehicle_size = vehicle_size
        self.license_plate = license_plate
        self.spot_size = spot_size
        self.spots_taken = []

    def clear_spots(self):
        for spot in self.spots_taken:
            spot.remove_vehicle(self)
        self.spots_taken = []

    def take_spot(self, spot):
        self.spots_taken.append(spot)

    @abc.abstractmethod
    def can_fit_in_spot(self, spot):
        pass


class Motorcycle(Vehicle):

    def __init__(self, license_plate):
        super(Motorcycle, self).__init__(VehicleSize.MOTORCYCLE, license_plate=license_plate, spot_size=1)

    def can_fit_in_spot(self, spot):
        return True


class Car(Vehicle):

    def __init__(self, license_plate):
        super(Car, self).__init__(VehicleSize.Car, license_plate=license_plate, spot_size=1)

    def can_fit_in_spot(self, spot):
        return True if (spot.size == VehicleSize.LARGE or spot.size == VehicleSize.COMPACT) else False


class Bus(Vehicle):

    def __init__(self, license_plate):
        super(Bus, self).__init__(VehicleSize.LARGE, license_plate, spot_size=5)

    def can_fit_in_spot(self, spot):
        return True if spot.size == VehicleSize.LARGE else False


class ParkingLot(object):

    def __init__(self, num_levels):
        self.num_levels = num_levels
        self.levels = []

    def park_vehicle(self, vehicle):
        for level in self.levels:
            if level.park_vehicle(vehicle):
                return True
        return False


class ParkingSpot(object):

    def __init__(self, level, row, spot_number, spot_size, vehicle_size):
        self.level = level
        self.row = row
        self.spot_number = spot_number
        self.spot_size = spot_size
        self.vehicle_size = vehicle_size
        self.vehicle = None

    def is_available(self):
        return True if self.vehicle is None else False

    def can_fit_vehicle(self, vehicle):
        if self.vehicle is not None:
            return False
        return vehicle.can_fit_in_spot(self)

    def park_vehicle(self, vehicle):
        pass

    def remove_vehicle(self):
        pass
