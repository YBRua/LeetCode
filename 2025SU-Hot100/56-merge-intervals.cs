using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 56-merge-intervals
    public class Solution56 {
        public int[][] Merge(int[][] intervals) {
            List<List<int>> merged = intervals.OrderBy(x => x[0])
                .Aggregate(new List<List<int>>(), (acc, curr) => {
                    if (acc.Count == 0 || acc[^1][1] < curr[0]) {
                        acc.Add([curr[0], curr[1]]);
                    } else {
                        acc[^1][1] = Math.Max(acc[^1][1], curr[1]);
                    }

                    return acc;
                });

            return [.. merged.Select(x => x.ToArray())];
        }
    }
}