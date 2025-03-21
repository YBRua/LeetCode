import random
from typing import List


# an optimized version of quick select
# that distributes duplicated pivots evenly to both sides
class QuickSelect:

    def quickselect(self, arr: List[int], k: int):
        return self._quick_select(arr, len(arr) - k, 0, len(arr) - 1)

    def _two_way_split(self, arr: List[int], left: int, right: int):
        pivot = arr[left]
        i, j = left + 1, right

        while i <= j:
            while i <= j and arr[i] < pivot:
                i += 1
            while i <= j and arr[j] > pivot:
                j -= 1

            if i <= j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1

        arr[left], arr[j] = arr[j], arr[left]
        return j

    def _quick_select(self, arr: List[int], k: int, left: int, right: int):

        split = self._two_way_split(arr, left, right)

        if split == k:
            return arr[split]
        elif split < k:
            return self._quick_select(arr, k, split + 1, right)
        else:
            return self._quick_select(arr, k, left, split - 1)


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
