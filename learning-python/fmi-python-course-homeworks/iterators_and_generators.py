from itertools import cycle
import math


def fibonacci():
    f1, f2 = 1, 1
    while True:
        yield f1
        f1, f2 = f2, f1 + f2


def primes():
    number = 2
    while True:
        if is_prime(number):
            yield number
        number += 1


def is_prime(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return n > 1


def alphabet(letters=None, code=None):
    if letters is not None:
        return letters
    elif code is not None:
        if code == 'lat':
            return (chr(n) for n in range(ord('a'), ord('z') + 1))
        elif code == 'bg':
            return (chr(n) for n in range(ord('а'), ord('я') + 1)
                    if n != ord('ы') and n != ord('э'))


def intertwined_sequences(sequence_specifications, generator_definitions=None):
    shortcuts = {'fibonacci': fibonacci(),
                 'primes': primes()}

    for current_sequence_specification in sequence_specifications:

        if current_sequence_specification['sequence'] not in shortcuts:
            additional_arguments = {key: value for key, value in current_sequence_specification.items()
                                    if key != 'sequence' and key != 'length'}

            if current_sequence_specification['sequence'] == 'alphabet':
                shortcuts['alphabet'] = alphabet(**additional_arguments)

            elif any(additional_arguments):
                shortcuts[current_sequence_specification['sequence']] = iter(
                    generator_definitions[current_sequence_specification['sequence']](**additional_arguments))
            else:
                shortcuts[current_sequence_specification['sequence']] = iter(
                    generator_definitions[current_sequence_specification['sequence']]())

        current_sequence = shortcuts[
            current_sequence_specification['sequence']]

        for _ in range(0, current_sequence_specification['length']):
            yield next(current_sequence)
