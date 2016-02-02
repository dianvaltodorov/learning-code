n = input()

res = 0
for i in xrange(n):
    st = raw_input()
    if '+' in st:
        res = res + 1
    elif '-' in st:
        res = res - 1

print(res)
