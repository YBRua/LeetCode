class Solution:
    # 233-number-of-digit-one
    def countDigitOne(self, n: int) -> int:
        n_str = str(n)
        n = len(n_str)

        dp = [[[0, 0] for _ in range(n + 1)] for _ in range(n + 1)]

        # dp[i][j][0/1]
        # building number from i-th digit,
        # with j digits being 1's
        for i in range(n + 1):
            dp[n][i][0] = i
            dp[n][i][1] = i

        i = n - 1
        while i >= 0:
            j = n - 1
            while j >= 0:

                # unbounded
                dp[i][j][0] = 9 * dp[i + 1][j][0] + dp[i + 1][j + 1][0]

                # bounded
                upper = int(n_str[i])
                for digit in range(upper + 1):
                    dp[i][j][1] += dp[i + 1][j + int(digit == 1)][int(digit == upper)]

                j -= 1
            i -= 1

        return dp[0][0][1]
