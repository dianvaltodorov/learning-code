n = input()

final = n * ['<'] + ['_'] + n * ['>']
start = n * ['>'] + ['_'] + n * ['<']


def new_valid_states(state, empty):
    states = []

    if empty - 1 >= 0 and state[empty - 1] == '>':
        new_state = list(state)
        new_state[empty], new_state[empty - 1] = new_state[empty - 1], new_state[empty]
        states.append((new_state, empty - 1))

    if empty - 2 >= 0 and state[empty - 2] == '>':
        new_state = list(state)
        new_state[empty], new_state[empty - 2] = new_state[empty - 2], new_state[empty]
        states.append((new_state, empty - 2))

    if empty + 1 <= 2 * n and state[empty + 1] == '<':
        new_state = list(state)
        new_state[empty], new_state[empty + 1] = new_state[empty + 1], new_state[empty]
        states.append((new_state, empty + 1))

    if empty + 2 <= 2 * n and state[empty + 2] == '<':
        new_state = list(state)
        new_state[empty], new_state[empty + 2] = new_state[empty + 2], new_state[empty]
        states.append((new_state, empty + 2))

    return states


def is_final_state(state):
    return ''.join(state) == ''.join(final)


path = []


def frog_leap(state, empty):
    if is_final_state(state):
        path.append(''.join(state))
        return True

    if not new_valid_states(state, empty):
        return False

    for s, empty in new_valid_states(state, empty):
        if (frog_leap(state=s, empty=empty)):
            path.append(''.join(state))
            return True

    return False


frog_leap(start, n)

for p in reversed(path):
    print p
