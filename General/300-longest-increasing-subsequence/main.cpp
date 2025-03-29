#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> max_lengths(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int candidate = 1;
                if (nums[j] < nums[i]) {
                    candidate = max(candidate, max_lengths[j] + 1);
                }
                max_lengths[i] = max(candidate, max_lengths[i]);
            }
        }

        return *max_element(max_lengths.begin(), max_lengths.end());
    }
};
