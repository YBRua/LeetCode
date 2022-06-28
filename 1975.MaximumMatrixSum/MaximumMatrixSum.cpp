#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // Observe that if the total number of negative values is even,
        // we can always swap and flip all of them to positive
        // so the max value is the sum of abs of all elements
        // Conversely, if the nubmer of neg values is odd,
        // there will be one negative value remaining
        // we can make this value the element with the least abs value
        // and compensate for the error by subtracting 2 * min_val
        int neg_counts = 0;
        long long matrix_sum = 0;
        int min_val = INT_MAX;
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[r].size(); ++c) {
                matrix_sum += abs(matrix[r][c]);
                min_val = min(min_val, abs(matrix[r][c]));
                if (matrix[r][c] < 0) {
                    neg_counts++;
                }
            }
        }
        if (neg_counts % 2 == 0) {
            return matrix_sum;
        } else {
            return matrix_sum - 2 * min_val;
        }
    }
};
