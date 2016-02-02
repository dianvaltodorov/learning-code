x = "123123123123"

print("Dido")


def trivial_solution(x):
    i = 0
    while i < len(x) - 1:
        j = i + 1
        while j < len(x):
            print(x[i], x[j])
            if x[i] == x[j]:
                return False
            j += 1
        i += 1
    return True


def trivial_solution_2(x):
    for i in range(len(x) - 1):
        for j in range(i + 1, len(x)):
            if x[i] == x[j]:
                return False
    return True


def set_solution(x):
    # Breakdown: Time O(N) [create the set] +++ O(N)[compare car by char]]
    return len(set(x)) == len(x)


def sort_solution(x):
    # sort the string O(N LogN) + O(N)
    # we can destroy it
    pass


def bit_mask_silution(x):
    bitmap = 0
    for c in x:
        mask = c - 'a'
        if bitmap & (1 << ord(mask)):
            return False
    return True


print(trivial_solution("asdfqwer"))
print(trivial_solution_2("asdfqwer"))
