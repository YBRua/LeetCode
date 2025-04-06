from collections import defaultdict, Counter
from typing import List, Dict


class Solution:
    # 1863-sum-of-all-subset-xor-totals
    def subsetXORSum(self, nums: List[int]) -> int:
        xor_sum = 0
        cnt = Counter(nums)

        def _dfs(i: int, visited: Dict[int, int], xor: int):
            nonlocal xor_sum
            xor_sum += xor

            for j in range(i + 1, len(nums)):
                curr = nums[j]
                if visited[curr] < cnt[curr]:
                    visited[curr] += 1
                    _dfs(j, visited, xor ^ curr)
                    visited[curr] -= 1

        visited = defaultdict(int)
        for i in range(len(nums)):
            visited[nums[i]] += 1
            _dfs(i, visited, nums[i])
            visited[nums[i]] -= 1

        return xor_sum
