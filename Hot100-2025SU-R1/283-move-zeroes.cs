namespace Hot100SU2025 {
    public class Solution283 {
        // 283-move-zeros
        public void MoveZeroes(int[] nums) {
            int left = 0, right = 0;
            while (right < nums.Length) {
                while (right < nums.Length && nums[right] == 0) {
                    right++;
                }

                if (right >= nums.Length) {
                    break;
                }

                nums[left] = nums[right];
                left++;
                right++;
            }

            while (left < nums.Length) {
                nums[left] = 0;
                left++;
            }
        }
    }
}