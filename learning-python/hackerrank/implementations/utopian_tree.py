import sys

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    res = 0
    for i in range(n + 2):
        if i % 2:
            res += 1
        else:
            res *= 2
    print(res)
