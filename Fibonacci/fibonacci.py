from typing import List

class Mat2D:
    def __init__(self, vals: List[List[int]]):
        self.vals = vals.copy()
        self.rows = len(vals)
        self.cols = len(vals[0])


def matmul(m1: Mat2D, m2: Mat2D) -> Mat2D:
    res = [[0] * 2 for _ in range(2)]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j] += m1.vals[i][k] * m2.vals[k][j]
    return Mat2D(res)


def fib(n: int):
    m = Mat2D([[1, 1], [1, 0]])
    res = Mat2D([[1, 1], [1, 0]])
    while n > 0:
        if (n % 2 == 1):
            res = matmul(res, m)
        n //= 2
        m = matmul(m, m)

    return res.vals[0][1]


def fast_power(x: int, y: int):
    """Computes x to the power of y"""
    res = 1
    while y > 0:
        if (y % 2 == 1):
            res *= x
        y //= 2
        x *= x

    return res


print(fast_power(2, 3))
