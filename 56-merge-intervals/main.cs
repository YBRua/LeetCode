// 56-merge-intervals
using System;
using System.Collections.Generic;

public class Solution_56 {
    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, (a, b) => {
            if (a[0] == b[0]) {
                return 0;
            } else if (a[0] < b[0]) {
                return -1;
            } else {
                return 1;
            }
        });

        List<int[]> res = new() {
            intervals[0]
        };

        for (int i = 1; i < intervals.Length; ++i) {
            if (intervals[i][0] <= res[^1][1]) {
                res[^1][1] = Math.Max(res[^1][1], intervals[i][1]);
            } else {
                res.Add(intervals[i]);
            }
        }

        return res.ToArray();
    }
}
