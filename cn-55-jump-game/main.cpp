#include <vector>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }

        int max_reachable = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i > max_reachable) {
                return false;
            }
            max_reachable = max(max_reachable, i + nums[i]);
        }

        if (max_reachable >= nums.size() - 1) {
            return true;
        } else {
            return false;
        }
    }
};
