# files = []
# for x in range(100000):
#     files.append(open('foo.txt', 'w'))


class File():

    def __init__(self, filename, mode):
        self.filename = filename
        self.mode = mode

    def __enter__(self):
        print("Entering")
        self.open_file = open(self.filename, self.mode)
        return self.open_file

    def __exit__(self, *args):
        print("exit")
        self.open_file.close()

files = []
for _ in range(10000):
    with File('foo.txt', 'w') as infile:
        infile.write('foo')
        files.append(infile)
