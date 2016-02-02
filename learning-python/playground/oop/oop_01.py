balance = 0


def deposit(amount):
    global balance
    balance += amount
    return balance


def withdraw(amount):
    global balance
    balance -= amount
    return balance


def play():
    balance = balance + 3
    print(balance)
