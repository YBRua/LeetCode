using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution763 {
        // 763-partition-labels
        public IList<int> PartitionLabels(string s) {
            Dictionary<char, int> lastIndex = [];

            for (int i = s.Length - 1; i >= 0; --i) {
                if (!lastIndex.ContainsKey(s[i])) {
                    lastIndex[s[i]] = i;
                }
            }

            int nextBoundary = 0;
            int prevBoundary = 0;
            List<int> res = [];

            for (int i = 0; i < s.Length; ++i) {
                nextBoundary = Math.Max(lastIndex[s[i]], nextBoundary);
                if (nextBoundary == i) {
                    res.Add(nextBoundary - prevBoundary + 1);
                    prevBoundary = nextBoundary + 1;
                }
            }

            return res;
        }
    }
}
