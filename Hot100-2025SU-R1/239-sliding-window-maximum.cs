using System.Collections.Generic;


namespace Hot100SU2025 {
    // 239-sliding-window-maximum
    public class Solution239 {
        public int[] MaxSlidingWindow(int[] nums, int k) {
            LinkedList<int> deque = new();
            List<int> res = [];

            for (int i = 0; i < nums.Length; ++i) {
                int curr = nums[i];
                while (deque.Count > 0 && nums[deque.Last.Value] < curr) {
                    deque.RemoveLast();
                }
                deque.AddLast(i);

                while (deque.Count > 0 && deque.First.Value <= i - k) {
                    deque.RemoveFirst();
                }

                if (i >= k - 1) {
                    res.Add(nums[deque.First.Value]);
                }
            }

            return [.. res];
        }
    }
}