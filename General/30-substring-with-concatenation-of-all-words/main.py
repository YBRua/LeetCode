from typing import List
from collections import defaultdict


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        block_size = len(words[0])
        n_blocks = len(words)

        targets = defaultdict(int)
        res = []

        for word in words:
            targets[word] += 1

        for i in range(block_size):
            tracker = defaultdict(int)

            left = i
            right = i
            while right <= len(s) and right + block_size <= len(s):
                new_segment = s[right : right + block_size]
                tracker[new_segment] += 1
                right += block_size

                while left < right and (right - left) // block_size > n_blocks:
                    drop_segment = s[left : left + block_size]
                    tracker[drop_segment] -= 1
                    left += block_size

                # print(left, right, new_segment, tracker)

                is_full = (right - left) // block_size == n_blocks
                is_valid = all(targets[key] == tracker[key] for key in tracker.keys())
                if is_full and is_valid:
                    res.append(left)

        return res


if __name__ == "__main__":
    s = "lingmindraboofooowingdingbarrwingmonkeypoundcake"
    words = ["fooo", "barr", "wing", "ding", "wing"]
    print(Solution().findSubstring(s, words))
