using System.Collections.Generic;
using System;

public class Solution {
    public IList<int> PathInZigZagTree(int label) {
        // determine height of the tree
        int height = 1;
        int minLabel = 1;
        while (label >= minLabel * 2) {
            height += 1;
            minLabel *= 2;
        }

        // find path
        var path = new List<int>();
        while (label != 0) {
            path.Add(label);
            int levelMax = Convert.ToInt32(Math.Pow(2, height)) - 1;
            int levelMin = Convert.ToInt32(Math.Pow(2, height - 1));
            label = Convert.ToInt32((levelMax + levelMin - label) / 2);
            height--;
        }

        path.Reverse();
        return path;
    }
}
