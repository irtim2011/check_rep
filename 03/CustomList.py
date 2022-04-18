class CustomList(list):

    def __init__(self, *args):
        if len(args) == 0:
            super().__init__()
        else:
            super().__init__()
            for element in args[0]:
                self.append(element)

    def __str__(self):
        return '%s, sum = %.2f' % (super().__str__(), sum(self))

    def __add__(self, other):
        c = CustomList()
        dif = abs(len(self) - len(other))
        if len(self) > len(other):
            x = CustomList(self)
            y = CustomList(other)
            y.extend([0] * dif)
        else:
            x = CustomList(self)
            x.extend([0] * dif)
            y = CustomList(other)
        for i in range(max(len(self), len(other))):
            c.append(x[i] + y[i])
        return c

    def __sub__(self, other):
        x = self
        y = []
        for i in range(len(other)):
            y.append((-1) * other[i])
        return x.__add__(y)

    def __radd__(self, other):
        return self.__add__(other)

    def __rsub__(self, other):
        x = other
        y = CustomList()
        for i in range(len(self)):
            y.append((-1) * self[i])
        return y.__radd__(x)

    def __gt__(self, other):
        if sum(self) > sum(other):
            return True
        return False

    def __eq__(self, other):
        if sum(self) == sum(other):
            return True
        return False

    def __lt__(self, other):
        if sum(self) < sum(other):
            return True
        return False
