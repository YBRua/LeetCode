from typing import List


class Solution:
    # 24-partition-labels
    def partitionLabels(self, s: str) -> List[int]:
        last_pos = {}
        for i, char in enumerate(s):
            last_pos[char] = i

        res = []
        boundary = 0
        prev = 0
        for i, char in enumerate(s):
            boundary = max(last_pos[char], boundary)
            if boundary == i:
                res.append(i - prev + 1)
                prev = i + 1

        return res
