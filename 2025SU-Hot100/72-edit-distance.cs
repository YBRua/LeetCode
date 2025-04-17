using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    // 72-edit-distance
    public class Solution72 {
        public int MinDistance(string word1, string word2) {
            int len1 = word1.Length;
            int len2 = word2.Length;

            int[,] ed = new int[len1 + 1, len2 + 1];

            for (int i = 0; i <= len1; ++i) {
                ed[i, 0] = i;
            }
            for (int j = 0; j <= len2; ++j) {
                ed[0, j] = j;
            }

            for (int i = 1; i <= len1; ++i) {
                for (int j = 1; j <= len2; ++j) {
                    int substitutionCost = word1[i - 1] == word2[j - 1] ? 0 : 1;
                    ed[i, j] = Math.Min(ed[i - 1, j - 1] + substitutionCost, Math.Min(ed[i - 1, j], ed[i, j - 1]) + 1);
                }
            }

            return ed[len1, len2];
        }
    }
}
