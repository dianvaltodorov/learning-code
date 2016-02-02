class Passenger:
    def __init__(self, elevator):
        self.elevator = elevator

    def issue_request(self, request):
        pass


class Request:
    def __init__(self):
        pass


class ELevator:
    def __init__(self):
        self.state = State.IDLE
        self.current_floor = 0
        self.requests = []

    def move_up(self):
        print "moving up"

    def move_down(self):
        pass

    def open_door(self):
        self.state = State.door_opened
        print "opening door"

    def close_door(self):
        self.state = State.door_opened
        print "opening door"

    def start_alarm():
        pass

    def get_current_floor():
        pass


class State():
    RUNNNING = 1
    DOOR_OPENED = 2
    IDLE = 3
    ALARMED = 4
    STOPPED = 5

el = ELevator()
p = Passenger(el)

print State.ALARMED
