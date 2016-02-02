def array_left_rotation(arr, size, rotations):
    first = rotations % size
    return arr[first:] + arr[:first]


# n, k = map(int, input().strip().split(' '))
# a = list(map(int, input().strip().split(' ')))
# answer = array_left_rotation(a, n, k)
# print(*answer, sep=' ')


def test_function():
    n = 5
    k = 4
    a = [1, 2, 3, 4, 5]
    res = array_left_rotation(a, n, k)
    assert res == [5, 1, 2, 3, 4]
