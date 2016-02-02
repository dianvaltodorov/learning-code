class BankAccout:

    def __init__(self):
        self._balance = 0

    def withdraw(self, amount):
        self._balance -= amount
        return self._balance

    def deposit(self, amount):
        self._balance += amount
        return self._balance

    def get_balance(self):
        return self._balance

a = BankAccout()
b = BankAccout()

a.deposit(100)
a.deposit(100)
b.deposit(100)
b.deposit(3000)

print(a.get_balance())
print(b.get_balance())


class MinimumBalanceAccount(BankAccout):
    def __init__(self, minimum_balance):
        BankAccout.__init__(self)
        self.minimum_balance = minimum_balance

    def withdraw(self, amount):
        if self._balance - amount < self.minimum_balance:
            print("sorry minimum balance must be maintained.")
        else:
            BankAccout.withdraw(self, amount)

mba = MinimumBalanceAccount(100)
mba.deposit(200)
mba.withdraw(100)
