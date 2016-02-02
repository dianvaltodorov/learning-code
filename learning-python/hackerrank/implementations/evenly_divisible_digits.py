import sys

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    yolo = n
    count = 0
    while yolo:
        d = yolo % 10

        if d != 0 and n % d == 0:
            count += 1
        yolo //= 10
    print(count)
