class Solution:
    # 233-number-of-digit-one
    def countDigitOne(self, n: int) -> int:
        n_str = str(n)
        n = len(n_str)

        dp = [[-1] * n for _ in range(n)]

        def _dfs(i: int, n_ones: int, is_limit: bool):
            if i == n:
                return n_ones
            if not is_limit and dp[i][n_ones] != -1:
                return dp[i][n_ones]

            res = 0
            upper = int(n_str[i]) if is_limit else 9
            for digit in range(upper + 1):
                res += _dfs(i + 1, n_ones + int(digit == 1), is_limit and digit == upper)

            if not is_limit:
                dp[i][n_ones] = res

            return res

        return _dfs(0, 0, True)
