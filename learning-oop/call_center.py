from abc import ABCMeta, abstractmethod

from collections import deque
from enum import Enum


class Rank(Enum):
    OPERATOR = 0
    SUPERVISOR = 1
    DIRECTOR = 2


class CallState(Enum):
    READY = 0
    IN_PROGRESS = 1
    COMPLETE = 2


class Employee(metaclass=ABCMeta):
    def __init__(self, employee_id, name, rank, call_center):
        self.call_center = call_center
        self.rank = rank
        self.name = name
        self.employee_id = employee_id

    def take_call(self, call):
        self.call = call
        self.call.employee = self
        self.call.state = CallState.IN_PROGRESS

    def complete_call(self):
        self.call.state = CallState.COMPLETE
        self.call_center.notify_call_completed(self.call)

    @abstractmethod
    def escalate_call(self):
        pass

    def _escalate_call(self):
        self.call.state = CallState.READY
        call = self.call
        self.call = None
        self.call_center.notify_call_escalated(call)


class Operator(Employee):
    def __init__(self, employee_id, name):
        super(Operator, self).__init__(employee_id, name, Rank.OPERATOR)

    def escalate_call(self):
        self.call.level = Rank.SUPERVISOR
        self._escalate_call()


class Supervisor(Employee):
    def __init__(self, employee_id, name):
        super(SUPERVISOR, self).__init__(employee_id, name, Rank.SUPERVISOR)
