public class Solution34 {
    public int[] SearchRange(int[] nums, int target) {
        // find lower bound
        int lb = -1;
        int left = 0, right = nums.Length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                lb = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // find upper bound
        int ub = -1;
        left = 0;
        right = nums.Length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                ub = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return new int[] { lb, ub };
    }
}
