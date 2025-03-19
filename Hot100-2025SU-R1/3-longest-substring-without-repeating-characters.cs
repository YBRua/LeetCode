using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution3 {
        // 3-longest-substring-without-repeating-characters
        public int LengthOfLongestSubstring(string s) {
            Dictionary<char, int> counter = new();
            int left = 0, right = 0, res = 0;
            while (right < s.Length) {
                char c = s[right];
                counter[c] = counter.GetValueOrDefault(c, 0) + 1;
                right++;

                while (counter[c] > 1) {
                    char cl = s[left];
                    counter[cl]--;
                    left++;
                }

                res = Math.Max(res, right - left);
            }

            return res;
        }
    }
}
