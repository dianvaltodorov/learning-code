SEPARATOR = "."


def extract_type(values, type_to_extract):
    extracted = str()
    for value in values:
        if type(value[0]) is type_to_extract:
            extracted += str(value[0]) * value[1]
    return extracted


def reversed_dict(input_):
    return dict(zip(input_.values(), input_))


def flatten_dict_recursion(data, parent_key):
    items = []
    for key, value in data.items():
        if len(parent_key) > 0:
            new_key = parent_key + SEPARATOR + key
        else:
            new_key = key
        if isinstance(value, dict):
            items.extend(flatten_dict_recursion(value, new_key).items())
        else:
            items.append((new_key, value))
    return dict(items)


def flatten_dict(data):
    return flatten_dict_recursion(data, "")


def unflatten_dict(data):
    unflattened_result = dict()
    for key, value in data.items():
        key_parts = key.split(SEPARATOR)
        d = unflattened_result
        for new_key in key_parts[:-1]:
            if new_key not in d:
                d[new_key] = dict()
            d = d[new_key]
        d[key_parts[-1]] = value
    return unflattened_result


def reps(data):
    return tuple(filter((lambda x: data.count(x) > 1), data))
