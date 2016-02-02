class Car:
    wheels = 4

    def __init__(self, make, model):
        self.make = make
        self.model = model

    @staticmethod
    def make_car_sound():
        print('VRooooommmm!')


