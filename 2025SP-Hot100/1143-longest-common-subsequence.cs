using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution1143 {
        // 1143-longest-common-subsequence
        public int LongestCommonSubsequence(string text1, string text2) {
            int len1 = text1.Length;
            int len2 = text2.Length;

            int[,] dp = new int[len1 + 1, len2 + 1];

            for (int i = 1; i <= len1; ++i) {
                for (int j = 1; j <= len2; ++j) {
                    dp[i, j] = text1[i - 1] == text2[j - 1] ? dp[i - 1, j - 1] + 1 : Math.Max(dp[i - 1, j], dp[i, j - 1]);
                }
            }

            return dp[len1, len2];
        }
    }
}
