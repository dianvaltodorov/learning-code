import collections
from random import choice

Card = collections.namedtuple('Card', ['rank', 'suit'])
print(Card)


class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('JDKA')
    suits = 'spades diamonds clubs hearts'.split()

    def __init__(self):
        self._cards = [Card(rank, suit) for suit in self.suits
                       for rank in self.ranks]

    def __len__(self):
        return len(self._cards)

    def __getitem__(self, position):
        return self._cards[position]


deck = FrenchDeck()
aces = deck[12::13]
beer_card = Card('7', 'diamonds')
random_card = choice(deck)
print(reversed(deck))
print(sorted(deck))
print(beer_card in deck)
print(beer_card)
print(deck[:3])
print(aces)

for card in deck:
    print(card)

# print(len(deck))
import ipdb
ipdb.set_trace()
