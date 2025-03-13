//  452-minimum-number-of-arrows-to-burst-balloons
using System;

public class Solution_452 {
    public int FindMinArrowShots(int[][] points) {
        Array.Sort(points, (a, b) => {
            if (a[1] == b[1]) {
                return 0;
            } else if (a[1] < b[1]) {
                return -1;
            } else {
                return 1;
            }
        });

        int n_arrows = 1;
        int pos = points[0][1];

        for (int i = 1; i < points.Length; ++i) {
            if (points[i][0] > pos) {
                ++n_arrows;
                pos = points[i][1];
            }
        }

        return n_arrows;
    }
}
