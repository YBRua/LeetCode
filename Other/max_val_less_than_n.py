from functools import reduce


class Solution:
    def _dfs(self, digits: list[int], n: int, ns: str, idx: int, seq: list[int], bounded: bool):
        if len(seq) == len(ns):
            val = reduce(lambda x, y: 10 * x + y, seq)
            if val >= n:
                return None
            return val

        if not bounded:
            seq.append(digits[-1])
            val = self._dfs(digits, n, ns, idx + 1, seq, False)
            seq.pop()
            return val

        digit_at_i = int(ns[idx])
        if digit_at_i in digits:
            seq.append(digit_at_i)
            val = self._dfs(digits, n, ns, idx + 1, seq, True)
            seq.pop()
            if val is not None:
                return val

        j = len(digits) - 1
        while j >= 0 and digits[j] >= digit_at_i:
            j -= 1

        if j >= 0:
            seq.append(digits[j])
            val = self._dfs(digits, n, ns, idx + 1, seq, False)
            seq.pop()
            return val

        return None

    def max_val_less_than_n(self, digits: list[int], n: int):
        digits.sort()
        ns = str(n)
        res = self._dfs(digits, n, ns, 0, [], True)
        if res is None:
            res = reduce(lambda x, y: x * 10 + y, [digits[-1] for _ in range(len(ns) - 1)])
        return res


if __name__ == "__main__":
    print(Solution().max_val_less_than_n([1, 2, 4, 9], 2533))
    print(Solution().max_val_less_than_n([4, 2, 9, 8], 988822))
    print(Solution().max_val_less_than_n([9, 8], 9))
    print(Solution().max_val_less_than_n([9, 6, 3, 5], 56449))
    print(Solution().max_val_less_than_n([5, 9], 5555))
