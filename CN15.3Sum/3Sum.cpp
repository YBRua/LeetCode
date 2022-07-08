#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ASC
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        vector<vector<int>> res;

        if (nums.size() < 3) return res; // cant have sol if fewer than 3 nums
        if (nums[low] > 0) return res; // cant have sol if all nums are positive
        // -4, -1, -1, 0, 1, 2
        for (low = 0; low < nums.size(); ++low) {
            if (low > 0 && nums[low] == nums[low - 1]) continue; // skip duplicates
            if (nums[low] > 0) break;

            high = nums.size() - 1;
            for (mid = low + 1; mid < high; ++mid) {
                if (mid > low + 1 && nums[mid] == nums[mid - 1]) continue; // skip dups
                
                // find high s.t. three-sum == 0
                while (mid < high && nums[low] + nums[mid] + nums[high] > 0) --high;

                // no sat
                if (mid >= high) break;
                if (nums[low] + nums[mid] + nums[high] == 0)
                    res.push_back({nums[low], nums[mid], nums[high]});
            }
        }

        return res;
    }
};
