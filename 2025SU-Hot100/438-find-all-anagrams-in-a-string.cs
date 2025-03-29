using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution438 {
        // 438-find-all-anagrams-in-a-string
        public IList<int> FindAnagrams(string s, string p) {
            List<int> res = new();
            Dictionary<char, int> pCounter = new();

            foreach (char ch in p) {
                pCounter[ch] = pCounter.GetValueOrDefault(ch, 0) + 1;
            }

            int windowSize = p.Length;
            int left = 0, right = 0;
            while (right < s.Length) {
                char ch = s[right];
                pCounter[ch] = pCounter.GetValueOrDefault(ch, 0) - 1;
                right++;
                while (pCounter[ch] < 0) {
                    char cl = s[left];
                    pCounter[cl]++;
                    left++;
                }

                if (right - left == windowSize) {
                    res.Add(left);
                }
            }

            return res.ToArray();
        }
    }
}
