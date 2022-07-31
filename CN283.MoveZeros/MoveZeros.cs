public class Solution {
    public void MoveZeroes(int[] nums) {
        int len = nums.Length;
        int left = 0;
        int right = 0;
        while (right < len) {
            if (nums[right] == 0 && right < len) {
                right++;
                continue;
            }
            if (right == len) {
                break;
            }
            nums[left] = nums[right];
            left++;
            right++;
        }
        while (left < len) {
            nums[left] = 0;
            left++;
        }
    }
}
