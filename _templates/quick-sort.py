from typing import List


# template code for quick select
# O(NlogN) on average, but O(N**2) in worst case
class Solution:
    def quick_sort(self, arr: List[int]):
        self._quick_sort(arr, 0, len(arr) - 1)
        return arr

    def _quick_sort(self, nums: List[int], begin: int, end: int):
        if begin >= end:
            return

        pivot_val = nums[begin]

        left = begin
        right = end

        while left < right:
            while left < right and pivot_val <= nums[right]:
                right -= 1

            if left < right:
                nums[left] = nums[right]

            while left < right and nums[left] < pivot_val:
                left += 1

            if left < right:
                nums[right] = nums[left]

        nums[left] = pivot_val

        self._quick_sort(nums, begin, left - 1)
        self._quick_sort(nums, left + 1, end)


def main():
    nums = [3, 5, 1, 67, 123, 42, 2, 0]
    print(Solution().quick_sort(nums))


if __name__ == "__main__":
    main()
