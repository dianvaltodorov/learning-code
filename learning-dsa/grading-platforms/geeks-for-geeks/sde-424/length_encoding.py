source = "aaaasssdd"
destination = ""


i = 0
while i < len(source):
    current = source[i]
    length = 1
    destination += current
    i = i + 1
    while i < len(source) and source[i] == current:
        i += 1
        length += 1
    destination += str(length)

print(destination)
