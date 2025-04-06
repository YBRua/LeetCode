using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution78 {
        // 78-subsets
        public void Dfs(int[] nums, int i, List<int> curr, List<List<int>> res) {
            res.Add([.. curr]);
            for (int j = i + 1; j < nums.Length; ++j) {
                curr.Add(nums[j]);
                Dfs(nums, j, curr, res);
                curr.RemoveAt(curr.Count - 1);
            }
        }

        public IList<IList<int>> Subsets(int[] nums) {
            var res = new List<List<int>>();
            Dfs(nums, -1, [], res);

            return res.ToArray();
        }
    }
}
