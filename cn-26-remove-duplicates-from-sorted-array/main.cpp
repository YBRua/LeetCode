#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int curr_p = 0, next_p = 0;

        if (!nums.size()) {
            return 0;
        }

        int k = 1;  // new length, for non-empty nums, we have at least 1 unique element

        while (next_p < nums.size() && curr_p < nums.size()) {
            while (next_p < nums.size() && nums[next_p] == nums[curr_p]) {
                next_p++;
            }
            if (next_p < nums.size()) {
                curr_p++;
                nums[curr_p] = nums[next_p];
                k++;
            }
        }

        return k;
    }
};
