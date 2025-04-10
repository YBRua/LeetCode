from collections import deque
from functools import reduce
from typing import List


class Solution:
    # 2999-count-the-number-of-powerful-integers
    def powerful_int_until(self, finish: int, limit: int, s: str):
        finish_str = str(finish)
        finish_len = len(finish_str)

        s_len = len(s)

        n = finish_len - s_len
        if n < 0:
            return 0

        dp = [[0, 0] for _ in range(n + 1)]

        # dp[i][1/0]: building prefixs from position i, either tight or unbounded
        dp[n][0] = 1
        dp[n][1] = int(int(finish_str[n:]) >= int(s))

        i = n - 1
        while i >= 0:
            digit = int(finish_str[i])

            # unbounded: previous unbounded result * (limit + 1)
            dp[i][0] = (limit + 1) * dp[i + 1][0]

            # tight: [0, digit-1] * previous unbounded + previous bounded
            if digit <= limit:
                dp[i][1] = digit * dp[i + 1][0] + dp[i + 1][1]
            else:
                # limit < digit, cannot be tight
                dp[i][1] = (limit + 1) * dp[i + 1][0]

            i -= 1

        return dp[0][1]

    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        return self.powerful_int_until(finish, limit, s) - self.powerful_int_until(
            start - 1, limit, s
        )
