using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution560 {
        // 560-subarray-sum-equals-k
        public int SubarraySum(int[] nums, int k) {
            int[] prefixSum = new int[nums.Length + 1];
            prefixSum[0] = 0;

            for (int i = 0; i < nums.Length; ++i) {
                prefixSum[i + 1] = prefixSum[i] + nums[i];
            }

            int count = 0;
            Dictionary<int, int> counter = new();
            // since k = s[i] - s[j] (i > j)
            // for each prefix sum s[i],
            // the number of j's such that i > j && s[j] = s[i] - k
            // is the number of subarrays equals to k
            foreach (int s in prefixSum) {
                count += counter.GetValueOrDefault(s - k, 0);
                counter[s] = counter.GetValueOrDefault(s, 0) + 1;
            }

            return count;
        }
    }
}