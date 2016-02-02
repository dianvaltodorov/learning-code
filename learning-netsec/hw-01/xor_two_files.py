import binascii

with open("pad", 'r') as pf:
    pad = pf.read()


def xor_strings(xs, ys):
    return ''.join([hex(t)[2:] for t in [ord(x) ^ ord(y) for x, y in zip(xs, ys)]])

filename = 'test.txt'
with open(filename, 'rb') as f:
    content = f.read()

hextext = binascii.hexlify(content)

binary_text = hextext.strip().decode("hex")
binary_pad = pad.strip().decode("hex")

with open("test", 'w') as of:
    of.write(xor_strings(binary_text, binary_pad))
