class Solution:
    mod = 10**9 + 7

    def fast_exponentiation(self, base: int, pow: int):
        res = 1
        while pow > 0:
            if pow % 2 == 1:
                res = res * base % self.mod

            base = base * base % self.mod
            pow = pow // 2

        return res

    def countGoodNumbers(self, n: int) -> int:

        if n == 0:
            return 0
        if n == 1:
            return 5
        if n == 2:
            return 20

        n_iter = (n - 1) // 2
        # power by square
        res = self.fast_exponentiation(20, n_iter)

        if n % 2 == 0:
            return 20 * res % self.mod
        else:
            return 5 * res % self.mod


if __name__ == "__main__":
    for i in range(1, 11):
        for j in range(1, 11):
            if Solution().fast_exponentiation(i, j) != i**j:
                raise ValueError()

    print("All good.")
