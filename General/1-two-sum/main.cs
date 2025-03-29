// 1-two-sum

using System.Collections.Generic;

public class SolutionTwoSum {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> counterpartIndex = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; ++i) {
            int counterpart = target - nums[i];
            if (counterpartIndex.ContainsKey(counterpart)) {
                return new int[] { counterpartIndex[counterpart], i };
            }
            counterpartIndex[nums[i]] = i;
        }

        return new int[] { -1, -1 };
    }
}
