from typing import List
from collections import defaultdict


class Solution:
    # 24-partition-labels
    def partitionLabels(self, s: str) -> List[int]:
        counter = defaultdict(int)
        for char in s:
            counter[char] += 1

        res = []
        seens = set()

        prev = 0
        for curr, char in enumerate(s):
            seens.add(char)
            counter[char] -= 1

            if all(counter[seen] == 0 for seen in seens):
                res.append(curr + 1 - prev)
                prev = curr + 1

        return res
