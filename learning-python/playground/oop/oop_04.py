class A:
    def f(self):
        return self.g()

    def g(self):
        return 'A'


class B(A):
    def g(self):
        return 'B'

a = A()
b = B()

print(a.f())
print(a.g())
print(b.f())
