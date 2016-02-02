def unique_in_order(iterable):
    if iterable is None | iterable is "":
        return []
    else:
        res = [iterable[0]]
        for x in iterable[1:]:
            if x != res[len(res) - 1]:
                res += [x]
    return res

print unique_in_order("")
