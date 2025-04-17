from typing import List


# 1534-count-good-triplets
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        max_val = max(arr)
        cnts = [0] * (max_val + 2)
        ans = 0

        for j, y in enumerate(arr):
            for k in range(j + 1, len(arr)):
                z = arr[k]
                if abs(y - z) > b:
                    continue

                left = max(y - a, z - c, 0)
                right = min(y + a, z + c, max_val)

                ans += max(cnts[right + 1] - cnts[left], 0)

            for v in range(y + 1, max_val + 2):
                cnts[v] += 1

        return ans
