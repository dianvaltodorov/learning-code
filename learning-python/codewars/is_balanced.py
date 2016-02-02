def is_balanced(source, caps):
    for c in source:
        if c in caps:
            stack = []
            if is_cap_closing:
                stack.append(c)
            else:
                stack.append(c)
