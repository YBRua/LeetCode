#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }

        // max profits when robbing first i houses
        vector<int> max_profits(nums.size());

        max_profits[0] = nums[0];
        max_profits[1] = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); ++i) {
            max_profits[i] = max(max_profits[i - 1], max_profits[i - 2] + nums[i]);
        }

        return max_profits[nums.size() - 1];
    }
};
