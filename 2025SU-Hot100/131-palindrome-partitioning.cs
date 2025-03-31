// 131-palindrome-partitioning
using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution131 {
        public void DfsSolver(List<List<string>> res, List<string> curr, string s, bool[,] isPalindrome, int start) {
            int n = s.Length;
            if (start == n) {
                res.Add([.. curr]);
                return;
            }

            for (int end = start; end < n; ++end) {
                if (isPalindrome[start, end]) {
                    curr.Add(s.Substring(start, end - start + 1));
                    DfsSolver(res, curr, s, isPalindrome, end + 1);
                    curr.RemoveAt(curr.Count - 1);
                }
            }
        }

        public IList<IList<string>> Partition(string s) {
            List<List<string>> res = [];
            int n = s.Length;
            bool[,] isPalindrome = new bool[n, n];

            for (int i = 0; i < n; ++i) {
                isPalindrome[i, i] = true;
            }
            for (int i = 1; i < n; ++i) {
                isPalindrome[i - 1, i] = s[i - 1] == s[i];
            }

            for (int len = 3; len <= n; ++len) {
                for (int start = 0; start < n; ++start) {
                    int end = start + len - 1;
                    if (end >= n) {
                        break;
                    }
                    isPalindrome[start, end] = isPalindrome[start + 1, end - 1] && s[start] == s[end];
                }
            }

            DfsSolver(res, [], s, isPalindrome, 0);

            return res.ToArray();
        }
    }
}
