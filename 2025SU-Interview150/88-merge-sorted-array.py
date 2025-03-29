from typing import List


# 88-merge-sorted-array
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        ptr1 = m - 1
        ptr2 = n - 1
        ptrw = m + n - 1

        while ptr1 >= 0 and ptr2 >= 0:
            if nums1[ptr1] > nums2[ptr2]:
                nums1[ptrw] = nums1[ptr1]
                ptrw -= 1
                ptr1 -= 1
            else:
                nums1[ptrw] = nums2[ptr2]
                ptrw -= 1
                ptr2 -= 1

        while ptr1 >= 0:
            nums1[ptrw] = nums1[ptr1]
            ptrw -= 1
            ptr1 -= 1

        while ptr2 >= 0:
            nums1[ptrw] = nums2[ptr2]
            ptrw -= 1
            ptr2 -= 1
