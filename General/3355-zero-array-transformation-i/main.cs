// 3355-zero-array-transformation-i

public class Solution3355 {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.Length + 1];

        // construct the difference array
        foreach (var query in queries) {
            diff[query[0]] += 1;
            diff[query[1] + 1] -= 1;
        }

        // prefix sum until diff[i]: maximum decrement at i
        // expect prefix_sum[i] > nums[i]
        int prefix_sum = 0;
        for (int i = 0; i < nums.Length; ++i) {
            prefix_sum += diff[i];
            if (nums[i] > prefix_sum) {
                return false;
            }
        }

        return true;
    }
}
