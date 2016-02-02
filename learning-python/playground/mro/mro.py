class BasePartyMixin(object):
    def play(self):
        super(BasePartyMixin, self).play()
        print "BasePartyMixin"


class PartyMixin(BasePartyMixin):
    def play(self):
        super(PartyMixin, self).play()
        print 'PartyMixin playing'


class FooMixin(object):
    def play(self):
        super(FooMixin, self).play()
        print 'FooMixin playing'
       

class BarMixin(object):
    def play(self):
        print 'BarMixin playing'

class A(PartyMixin, FooMixin, BarMixin):
    def play(self):
        super(A, self).play()
        print 'A playing'

a = A()
a.play()
