
class StoneException(RuntimeError):
    def __init__(self, m, t=None):
        if t is None:
            super().__init__(m)
        else:
            super().__init__(m + " " + t.location())
