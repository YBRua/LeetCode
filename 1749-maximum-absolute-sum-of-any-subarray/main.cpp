#include <vector>

using namespace std;

class Solution {
   public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_sums(n);
        vector<int> max_sums(n);

        min_sums[0] = nums[0];
        max_sums[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            min_sums[i] = min(nums[i], min_sums[i - 1] + nums[i]);
            max_sums[i] = max(nums[i], max_sums[i - 1] + nums[i]);
        }

        int max_abs_sum = 0;
        for (int i = 0; i < n; ++i) {
            int candidate = max(abs(min_sums[i]), abs(max_sums[i]));
            max_abs_sum = max(max_abs_sum, candidate);
        }

        return max_abs_sum;
    }
};
