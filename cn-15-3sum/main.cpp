#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        // skip duplicated starts
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int k = n - 1;
            for (int j = i + 1; j < n; ++j) {
                // skip duplicate starts
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                while (j < k && nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }

                if (j == k) {
                    break;
                }

                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return ans;
    }
};
