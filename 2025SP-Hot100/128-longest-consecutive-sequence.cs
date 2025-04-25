using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution128 {
        // 128-longest-consecutive-sequence
        public int LongestConsecutive(int[] nums) {
            HashSet<int> numsSet = new(nums);
            int longestStreak = 0;

            foreach (int num in numsSet) {
                if (!numsSet.Contains(num - 1)) {
                    int current = num;
                    int currentStreak = 1;
                    while (numsSet.Contains(current + 1)) {
                        current++;
                        currentStreak++;
                    }
                    longestStreak = Math.Max(longestStreak, currentStreak);
                }
            }

            return longestStreak;
        }
    }
}
