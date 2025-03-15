// 162-find-peak-element
public class Solution162 {
    public int FindPeakElement(int[] nums) {
        if (nums.Length == 1) {
            return 0;
        }

        int left = 0, right = nums.Length;
        while (left <= right) {
            int mid = (left + right) / 2;

            // edge cases: assume nums[-1] == nums[n] == -\infty
            if (mid == 0) {
                if (nums[0] > nums[1]) {
                    return 0;
                } else {
                    mid = left + 1;
                }
            }
            if (mid == nums.Length - 1) {
                if (nums[nums.Length - 1] > nums[nums.Length - 2]) {
                    return nums.Length - 1;
                } else {
                    mid = right - 1;
                }
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
}
