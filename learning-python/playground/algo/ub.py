input = "foo.o: foo.c\n\tgcc foo.c\nbar.0: bar.c\n\tgcc bar.c\ntar.o: tar.c\n\tgcc tar.o\nmain: tar.o foo.o bar.o \n\tlink tar.o main.o foo.o";
print(input)

lines = input.split('\n')
c = [l[1:] for l in lines if '\t' in l]
t = [l.split(':')[0] for l in lines if ':' in l]
n = len(t)
d = [l.split(':')[1].strip().split(' ') for l in lines if ':' in l]

print c
print t
print d

dependencies = dict()
commands = dict()

for i in range(len(t)):
    dependencies[t[i]] = d[i]
    commands[t[i]] = c[i]

print dependencies
print commands

used = dict((x, 0) for x in t)

print used

def dfs(v):
    used[v] = 1
    for deps in dependencies[v]:
        if used[deps] != 0:
            dfs(deps)
            print(commands[deps])

dfs('main')
