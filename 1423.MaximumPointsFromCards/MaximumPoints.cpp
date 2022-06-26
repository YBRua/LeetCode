// HINT: Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tot_sum = 0;
        int window_size = n - k;
        int window_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i < window_size) {
                window_sum += cardPoints[i];
            }
            tot_sum += cardPoints[i];
        }

        int min_val = window_sum;
        for (int i = window_size; i < n; ++i) {
            window_sum = window_sum + cardPoints[i] - cardPoints[i - window_size];
            min_val = min(min_val, window_sum);
        }

        return tot_sum - min_val;
    }
};
