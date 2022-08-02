using System;

public class Solution {
    public int KthSmallest(int[][] matrix, int k) {
        int n = matrix.Length; // [n, n] matrix
        int left = matrix[0][0], right = matrix[n-1][n-1];
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (_numLE(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    private int _numLE(int[][] matrix, int val) {
        int c = matrix.Length - 1;
        int r = 0;

        int count = 0;
        for (r = 0; r < matrix.Length; ++r) {
            while (c >= 0 && matrix[r][c] > val) {
                --c;
            }
            count += (c + 1);
        }

        return count;
    }
}
