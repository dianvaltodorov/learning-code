from abc import ABCMeta, abstractmethod
from enum import Enum


class Suit(Enum):

    HEART = 0
    DIAMOND = 1
    CLUBS = 2
    SPADE = 3

class Card(metaclass=ABCMeta):

    def __init__(self, value, suit):
        self.value = value
        self.suit = suit
        self.is_available = True

    @property
    @abstractmethod
    def value(self):
        pass

    @value.setter
    @abstractmethod
    def value(self, other):
        pass


class BlackJackCard(Card):

    def __init__(self, value, suit):
        super(BlackJackCard, self).__init__(value, suit)

    def is_ace(self):
        return self._value == 1

    def is_face_card(self):
        """Jack = 11, Queen = 12, King = 13"""
        return 10 < self._value <= 13

    @property
    def value(self):
        if self.is_ace() == 1:
            return 1
        elif self.is_face_card():
            return 10
        else:
            return self._value

    @value.setter
    def value(self, new_value):
        if 1 <= new_value <= 13:
            self._value = new_value
        else:
            raise ValueError('Invalid card value: {}'.format(new_value))
