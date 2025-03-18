# 2401-longest-nice-subarray
from typing import List


class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        bit_flags = 0
        left = 0
        right = 0
        max_length = 0
        while right < len(nums):
            new_num = nums[right]
            while bit_flags & new_num != 0:
                bit_flags &= ~nums[left]
                left += 1

            bit_flags |= new_num
            max_length = max(max_length, right - left + 1)

            right += 1

        return max_length


def main():
    nums = [1, 3, 8, 48, 10]

    for num in nums:
        # 32-bit binary representation
        print(f"{num:3d} -> {num:032b}")


if __name__ == "__main__":
    main()
