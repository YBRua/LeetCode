import random
from typing import List


# an optimized version of quick select
# that splits the array into three parts (less than, equal to, greater than the pivot)
# and recursively searches the k-th smallest element in the corresponding part
# https://github.com/YKitty/Notes
# Still O(N) on average, but O(N**2) in worst case
class QuickSelect:

    def quickselect(self, arr: List[int], k: int):
        print("-" * 50)
        print(arr, k, len(arr) - k)
        return self._quick_select(arr, len(arr) - k, 0, len(arr) - 1)

    def _three_way_split(self, arr: List[int], left: int, right: int):
        # lt: last index < pivot
        # gt: last index > pivot
        # index: current index
        # 1. current > pivot: swap curr with gt - 1, gt -= 1
        # 2. current < pivot: swap curr with lt + 1, lt += 1
        # 3. current == pivot: index += 1
        print(f"arr: {arr}")
        print(f"left: {left}, right: {right}")
        pivot = arr[left]
        print(f"pivot: {pivot}")

        lt = left - 1
        index = left
        gt = right + 1

        while index < gt:
            if arr[index] < pivot:
                arr[lt + 1], arr[index] = arr[index], arr[lt + 1]
                lt += 1
                index += 1
            elif arr[index] > pivot:
                arr[index], arr[gt - 1] = arr[gt - 1], arr[index]
                gt -= 1
            else:
                index += 1

        print(arr, f"| lt: {lt}, gt: {gt}, pivot: {pivot}")

        return lt, gt, pivot

    def _quick_select(self, arr: List[int], k: int, left: int, right: int):

        (lt, gt, pivot) = self._three_way_split(arr, left, right)

        if lt < k < gt:
            return pivot
        elif k <= lt:
            return self._quick_select(arr, k, left, lt)
        else:
            return self._quick_select(arr, k, gt, right)


# test
def main():
    arr = [3, 2, 1, 5, 6, 4]
    k = 2
    print(QuickSelect().quickselect(arr, k))  # 5

    arr = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    print(QuickSelect().quickselect(arr, k))  # 4

    arr = list(range(1, 11)) + [1] * 20
    k = 30
    print(QuickSelect().quickselect(arr, k))  # 1


if __name__ == "__main__":
    main()
