public class Solution {
    private int _quickSelect(int[] nums, int k, int low, int high) {
        int pivot = nums[low];
        int left = low, right = high;
        while (left < right) {
            while (left < right && nums[right] <= pivot) {
                --right;
            }
            while (left < right && nums[left] >= pivot) {
                ++left;
            }
            if (left < right) {
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;
            }
        }
        nums[low] = nums[left];
        nums[left] = pivot;

        if (k == left) {
            return nums[left];
        } else if (k < left) {
            return _quickSelect(nums, k, low, left - 1);
        } else if (k > right) {
            return _quickSelect(nums, k, left + 1, high);
        }
        return -1; // should never be here
    }
    public int FindKthLargest(int[] nums, int k) {
        return _quickSelect(nums, k - 1, 0, nums.Length - 1);
    }
}
