def list_to_array(lst):
    if lst is None:
        return []
    else:
        return [lst.value] + list_to_array(lst.next)
