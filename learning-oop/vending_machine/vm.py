from abc import ABCMeta, abstractmethod
from collections import namedtuple

class AbstractVendingMachine(metaclass=ABCMeta):

    @abstractmethod
    def receive_selection(self):
        pass

    @abstractmethod
    def receive_payment(self):
        pass

    @abstractmethod
    def get_change(self):
        pass


Item = namedtuple("Item", ["name", "price"])
Coin = namedtuple("Coin", ["name", "value"])


class ProductInventory:

    def __init__(self):
        self.inventory = dict()

    def add(self, item, count):
        self.inventory[item] = count

    def deduct(self, item):
        if self.inventory[item] > 0:
            self.inventory[item] -= 1

    def has_item(self, item):
        return self.inventory[item]

    def products(self):
        return [k for k, v in self.inventory.items() if v > 0]


class CashInventory:

    def __init__(self):
        self.cash = dict()

    def add(self, coin, count):
        self.cash[coin] = count

    def deduct(self, coin):
        if self.cash[coin] > 0:
            self.cash[coin] -= 1


class VendingMachine(AbstractVendingMachine):

    def __init__(self, product_inventory, cash_inventory):
        self.product_inventory = product_inventory
        self.cash_inventory = cash_inventory
        self.current_balance = 0
        self.current_selection = None

    @property
    def menu(self):
        products = self.product_inventory.products()
        menu = {i: products[i] for i in range(len(products))}
        return menu

    def print_menu(self):
        print(self.menu)

    def receive_selection(self):
        option = int(input())
        self.current_selection = self.menu[option]


    def process_selection(self):

        while not self.is_full_paid():
            print("DIdo")
            self.receive_payment()

        change = vm.get_change()
        print

    def validate_availability(self):
        pass

    def receive_payment(self):
        self.current_balance += int(input())

    def get_change(self):
        pass

    def is_full_paid(self):
        return self.current_balance > self.current_selection.price


class VendingMachineFactory():

    @staticmethod
    def get_vanding_machine():
        product_inventory = ProductInventory()
        product_inventory.add(Item("Waffle", 20), 1)
        product_inventory.add(Item("Waffle", 20), 1)
        product_inventory.add(Item("Waffle", 20), 1)
        product_inventory.add(Item("Waffle", 20), 1)
        product_inventory.add(Item("Pepsi", 10), 1)
        product_inventory.add(Item("Pepsi", 10), 1)
        product_inventory.add(Item("Pepsi", 10), 1)
        product_inventory.add(Item("Chips", 10), 1)
        product_inventory.add(Item("Chips", 10), 1)
        product_inventory.add(Item("Chips", 10), 1)

        cash_inventory = ProductInventory()
        cash_inventory.add(1, 10)
        cash_inventory.add(2, 10)
        cash_inventory.add(5, 10)
        cash_inventory.add(10, 10)
        cash_inventory.add(20, 10)
        cash_inventory.add(100, 10)
        vm = VendingMachine(product_inventory, cash_inventory)
        return vm


if __name__ == '__main__':
    vm = VendingMachineFactory.get_vanding_machine()
    vm.print_menu()
    vm.receive_selection()
    vm.process_selection()
    print(vm.get_change())
    vm.reset()
